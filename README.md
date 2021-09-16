# input

A simple `read` replacement which:
- Allows the use of arrow keys
- May have command history based on a history file
- Doesn't depend on your shell


## Usage
```bash
input [-p PROMPT] [-H PATH]
```

## Example
```bash
variable="$(input -p "Example Prompt: " -H ~/.history)"
echo "$variable"
```

Next time the command is run, press up to see the last answer!

## Note
GNU readline is required for building
