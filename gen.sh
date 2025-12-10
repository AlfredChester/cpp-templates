#!/opt/homebrew/bin/bash

# Initialize recursive option to false
RECURSIVE=false

# Check if the first argument is the -r option
if [ "$1" == "-r" ]; then
  RECURSIVE=true
  shift  # Skip the first argument -r, subsequent arguments are all directories
fi

# Create a function to process a single directory
process_directory() {
  local current_dir="$1"
  local output_file="$current_dir/config.yml"
  
  # Clear or create the config.yml file
  echo "contents:" | iconv -t UTF-8 > "$output_file"

  # Create an associative array to track processed files
  declare -A processed_files

  # Iterate through the current directory and files
  for entry in "$current_dir"/*; do
    if [ -d "$entry" ]; then
      # Process subdirectories
      dir_name=$(basename "$entry")
      echo "  - name: $dir_name" | iconv -t UTF-8 >> "$output_file"
      echo "    directory: $dir_name" | iconv -t UTF-8 >> "$output_file"
      
      # If recursive is enabled, recursively call the function for subdirectories
      if [ "$RECURSIVE" = true ]; then
        process_directory "$entry"
      fi
    elif [ -f "$entry" ]; then
      # Get the filename
      filename=$(basename "$entry")
      
      # Skip the config.yml file in the current directory
      if [ "$filename" == "config.yml" ]; then
        continue
      fi

      # Check the file type and get the base name
      if [[ "$filename" == *.hpp ]]; then
        base_name="${filename%.hpp}"
      elif [[ "$filename" == *.py ]]; then
        base_name="${filename%.py}"
      elif [[ "$filename" == *.h ]]; then
        base_name="${filename%.h}"
      elif [[ "$filename" == *.json ]]; then
        base_name="${filename%.json}"
      elif [[ "$filename" == *-pre.tex ]]; then
        base_name="${filename%-pre.tex}"
      elif [[ "$filename" == *-post.tex ]]; then
        base_name="${filename%-post.tex}"
      else
        echo "Unrecognized file: $filename"
        continue  # Skip other unrelated files
      fi
      
      # If this file has not been processed before
      if [ -z "${processed_files[$base_name]}" ]; then
        processed_files[$base_name]=1  # Mark as processed

        # Prepare to start generating entries
        echo "  - name: $base_name" | iconv -t UTF-8 >> "$output_file"

        # Collect possible codes into an array
        echo "    codes:" | iconv -t UTF-8 >> "$output_file"

        if [ -f "$current_dir/$base_name.hpp" ]; then
          echo "      - $base_name.hpp" | iconv -t UTF-8 >> "$output_file"
        fi
        if [ -f "$current_dir/$base_name.h" ]; then
          echo "      - $base_name.h" | iconv -t UTF-8 >> "$output_file"
        fi
        if [ -f "$current_dir/$base_name.json" ]; then
          echo "      - $base_name.json" | iconv -t UTF-8 >> "$output_file"
        fi
        if [ -f "$current_dir/$base_name.py" ]; then
          echo "      - $base_name.py" | iconv -t UTF-8 >> "$output_file"
        fi

        # Process pre-code and post-code files
        if [ -f "$current_dir/$base_name-pre.tex" ]; then
          echo "    code-pre: $base_name-pre.tex" | iconv -t UTF-8 >> "$output_file"
        fi
        if [ -f "$current_dir/$base_name-post.tex" ]; then
          echo "    code-post: $base_name-post.tex" | iconv -t UTF-8 >> "$output_file"
        fi
      fi
    fi
  done

  echo "Generated config.yml file at: $output_file"
}

for dir in "$@"; do
  if [ -d "$dir" ]; then
    process_directory "$dir"
  else
    echo "Warning: $dir is not a valid directory, skipping processing."
  fi
done