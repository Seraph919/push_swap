#!/bin/bash

generate_numbers() {
  numbers=()
  used=()
  count=0

  while [ $count -lt 50 ]; do
    num=$((RANDOM % 1000))
    if [[ -z "${used[$num]}" ]]; then
      numbers+=($num)
      used[$num]=1
      ((count++))
    fi
  done

  echo "${numbers[@]}"
}

# Generate and clean numbers
numbers=$(generate_numbers | sed 's/^[ \t]*//;s/[ \t]*$//')  # Remove leading/trailing spaces

echo "Generated numbers:"
echo "$numbers"

# Run push_swap and capture output
echo "Running push_swap:"
output=$(./push_swap $numbers | cat -v)
echo "$output"

# Count lines of output and check with checker
line_count=$(echo "$output" | wc -l)
echo "Line count: $line_count"
echo "$output" | ./checker_linux $numbers
