#!/bin/bash

# Check if the script was given at least two arguments
if [ $# -lt 2 ]; then
  echo "Usage: $0 <output_file.md> <input_file1.md> [<input_file2.md> ...]"
  exit 1
fi

# Save the output file name
OUTPUT_FILE=$1

# Loop over the input files and process each one
for ((i=2; i<=$#; i++)); do
  # Get the i-th input file name
  INPUT_FILE=${!i}

  # Read the input file line by line
  while read -r line; do
    # Check if the line starts with one or more '#' characters
    if [[ $line =~ ^#+ ]]; then
      # Add an HTML comment under the header and save it to the output file
      echo "${line}" >> "${OUTPUT_FILE}"
      echo "<!-- from $INPUT_FILE -->" >> "${OUTPUT_FILE}"
    else
      # Save the line to the output file
      echo "${line}" >> "${OUTPUT_FILE}"
    fi
  done < "${INPUT_FILE}"
  echo -e "\n" >> "${OUTPUT_FILE}"
done
