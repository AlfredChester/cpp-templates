import posixpath
import re
import os
import yaml
import argparse


def escape_latex_special_chars(text):
    """
    转义 LaTeX 特殊字符，包括: _ % $ # & { } ~ ^
    """
    special_chars = {
        "\\": r"\textbackslash{}",
        "&": r"\&",
        "%": r"\%",
        "$": r"\$",
        "#": r"\#",
        "_": r"\_",
        "{": r"\{",
        "}": r"\}",
        "~": r"\textasciitilde{}",
        "^": r"\textasciicircum{}",
    }
    return re.sub(
        "|".join(re.escape(key) for key in special_chars.keys()),
        lambda match: special_chars[match.group()],
        text,
    )


def read_file(file_path):
    if not os.path.isfile(file_path):
        raise FileNotFoundError(f"文件不存在：{file_path}")

    with open(file_path, "r", encoding="UTF-8") as f:
        return f.read()


def get_config(directory, filename=None):
    config_paths = []

    if filename:
        config_paths.append(posixpath.join(directory, filename))

    config_paths += [
        posixpath.join(directory, "config.yml"),
        posixpath.join(directory, "config.yaml"),
    ]

    for config_path in config_paths:
        if not os.path.isfile(config_path):
            continue

        with open(config_path, "r", encoding="UTF-8") as f:
            config = yaml.safe_load(f)
            if config is None:
                continue

            return config

    raise FileNotFoundError(f"目录 {directory} 未找到配置文件")


def detect_style_by_extension(filename: str) -> str:
    """根据文件扩展名返回 LaTeX lstlisting style"""
    if (
        filename.endswith(".cpp")
        or filename.endswith(".hpp")
        or filename.endswith(".h")
    ):
        return "cppstyle"
    elif filename.endswith(".java"):
        return "javastyle"
    elif filename.endswith(".py"):
        return "pythonstyle"
    else:
        return ""  # 默认无 style


# 生成代码块 LaTeX 内容
def generate_latex_for_item(directory, item, depth):
    latex_parts = []

    if "name" not in item:
        raise ValueError(f"目录 {directory} 配置文件有误（未配置 name）")

    name = escape_latex_special_chars(item.get("name"))

    if depth == 0:
        latex_parts.append(f"\\section{{{name}}}\n")
    elif depth == 1:
        latex_parts.append(f"\\subsection{{{name}}}\n")
    elif depth == 2:
        latex_parts.append(f"\\subsubsection{{{name}}}\n")
    else:
        raise ValueError(f"目录 {directory} 配置过深")

    # 处理 code-pre
    if "code-pre" in item:
        file_path = posixpath.join(directory, item["code-pre"])
        contents = read_file(file_path)
        latex_parts.append(contents + "\n")

    # 处理 codes (支持字符串或数组)
    if "codes" in item:
        codes_value = item["codes"]

        if isinstance(codes_value, str):  # 单个文件
            codes_list = [codes_value]
        elif isinstance(codes_value, list):  # 多个文件
            codes_list = codes_value
        elif codes_value is None:  # 空值
            codes_list = []
        else:
            raise ValueError(f"codes 字段格式错误: {codes_value}")

        for code_file in codes_list:
            file_path = posixpath.join(directory, code_file)
            if not os.path.isfile(file_path):
                raise FileNotFoundError(f"代码文件不存在：{file_path}")

            style = detect_style_by_extension(code_file)
            if style:
                latex_parts.append(f"\\lstinputlisting[style={style}]{{{file_path}}}\n")
            else:
                latex_parts.append(f"\\lstinputlisting{{{file_path}}}\n")

    # 处理 code-post
    if "code-post" in item:
        file_path = posixpath.join(directory, item["code-post"])
        contents = read_file(file_path)
        latex_parts.append(contents + "\n")

    return "\n".join(latex_parts)


def generate_latex_from_config(directory, depth=0):
    config = get_config(directory)

    latex_sections = []
    for item in config.get("contents") or []:
        if "directory" in item:
            subdir_path = posixpath.join(directory, item["directory"])

            if not os.path.isdir(subdir_path):
                raise NotADirectoryError(f"子目录不存在或不是目录：{subdir_path}")

            latex_sections.append(generate_latex_for_item(directory, item, depth))
            latex_sections.append(generate_latex_from_config(subdir_path, depth + 1))
        else:
            latex_sections.append(generate_latex_for_item(directory, item, depth))

    return "\n".join(latex_sections)


def generate_latex(root_dir, root_config_filename=None):
    config = get_config(root_dir, root_config_filename)

    latex_pre = ""
    latex_post = ""

    if "latex-pre" in config:
        latex_pre_path = config["latex-pre"]
        latex_pre = read_file(latex_pre_path)

    title = escape_latex_special_chars(config.get("title", "UESTC Nanana Templates"))
    author = escape_latex_special_chars(config.get("author", "UESTC_Nanana"))

    latex_pre = latex_pre.replace("{PLACEHOLDER:TITLE}", title).replace(
        "{PLACEHOLDER:AUTHOR}", author
    )

    if "latex-post" in config:
        latex_post_path = config["latex-post"]
        latex_post = read_file(latex_post_path)

    code_root = config.get("root-directory", "./templates")

    if not os.path.isdir(code_root):
        raise NotADirectoryError(f"模板根目录不存在或不是一个目录：{code_root}")

    latex_content = generate_latex_from_config(code_root)

    return latex_pre + latex_content + latex_post


def write_latex_file(latex_content, output_file):
    try:
        with open(output_file, "w", encoding="UTF-8") as f:
            f.write(latex_content)
    except IOError as e:
        raise IOError(f"无法写入输出文件 {output_file}: {e}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate LaTeX from templates.")
    parser.add_argument("--root-dir", default="./", help="Specify the root directory.")
    parser.add_argument(
        "--config-file",
        default=None,
        help="Specify the config file name in the root directory.",
    )
    parser.add_argument(
        "--output-file", default="output.tex", help="Specify the output file name."
    )
    args = parser.parse_args()

    latex_content = generate_latex(args.root_dir, args.config_file)
    write_latex_file(latex_content, args.output_file)
    print(f"LaTeX 文件已生成：{args.output_file}")
