import json, os

def create(name, prefix, body, description):
    res = {}
    res[name] = {}
    res[name]['prefix'] = prefix
    res[name]['body'] = body
    res[name]['description'] = description
    return res
def parseFile(file):
    f = open(file, 'r')
    body = []
    for line in f:
        if line[-1] == '\n':
            line = line[:-1]
        body.append(line)
    return body

body = parseFile('input.txt')

with open('output.json', 'w') as f:
    data = create('test', 'test', body, 'test')
    f.write(json.dumps(data))





# Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
# description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
# $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
# same ids are connected.
# Example:
# "Print to console": {
	# "prefix": "log",
	# "body": [
		# "console.log('$1');",
		# "$2"
	# ],
	# "description": "Log output to console"
# }