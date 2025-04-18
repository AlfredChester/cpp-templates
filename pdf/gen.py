# verification-helper: IGNORE 1

import re, os, hashlib, yaml


scl = yaml.safe_load(open(os.path.join("scl.yaml")).read())

LANGS = {
    "c": "C",
    "cpp": "C++",
    "hpp": "C++",
    "h": "C++",
    "py": "Python",
    "pl": "Perl",
    "sh": "sh",
    "java": "Java",
    "json": "C++",
}


def lang(ext):
    if not ext:
        return "{}"
    ext = ext.lower()
    return LANGS[ext] if ext in LANGS else "{}"


def gen_section(sect_yaml):
    global line_count

    name = sect_yaml["name"]
    dirname = sect_yaml["dir"]
    files = sect_yaml["files"]

    sect = []
    sect.append("\\section{%s}" % name.replace(" ", ""))

    subsects = []
    for idx, f in enumerate(files):
        title = f["title"]
        fname = f["fname"]
        desc = f.get("desc", None)

        extension = fname.split(".")[-1]

        sect.append("\\subsection{%s}" % title)

        def digest_line(s):
            return hashlib.md5(re.sub(r"\s|//.*", "", s).encode()).hexdigest()[-4:]

        with open("src/%s/%s" % (dirname, fname), "r") as fp:
            code = fp.read()

        line_count = 1

        for line in code.split("\n"):
            sect.append("\\createlinenumber{%d}{%d}" % (line_count, line_count))
            line_count += 1

        if desc:
            sect.append("\\begin{mdframed}[hidealllines=true,backgroundcolor=blue!5]")
            sect.append(desc.strip().replace(" ", ""))
            sect.append("\\end{mdframed}\\vspace{-10pt}")

        # "src/%s/%s"
        sect.append(
            "\\lstinputlisting[caption={\\bf%s}," % fname
            + "label={%s}," % fname
            + "language=%s" % lang(extension)
            + "]{../src/%s%s}" % (dirname, fname)
        )

        # sect.append("\\begin{verbatim}[language=%s]" % lang(extension))
        # sect.append(code.replace("$", "{dollar}"))
        # sect.append("\\end{verbatim}")

    return "\n".join(sect)


for section in scl:
    print(gen_section(section))
