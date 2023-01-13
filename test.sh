#!/bin/bash
filename="minishell"
if [ -f "$filename" ]; then
echo "File exists"
else
echo "File does not exist"
fi