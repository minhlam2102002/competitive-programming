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
    name = os.path.basename(file).split('.')[0]
    prefix = file[2:]
    if name == 'template':
        prefix = 'cpp/template'
    body = []
    description = name
    for line in f:
        if 'template' not in name:
            if '<bits/stdc++.h>' in line:
                continue
            if 'using namespace std;' in line:
                continue
            if "Verified: " in line:
                description += '\n' + line.split('// ')[1].strip()
                continue
        if line[-1] == '\n':
            line = line[:-1]
        body.append(line)

    return name, prefix, body, description
def loadFile():
    files = []
    for r, d, f in os.walk('./'):
        for file in f:
            if file.endswith(".cpp"):
                files.append(os.path.join(r, file))
    return files
files = loadFile()
data = {}
for file in files:
    data.update(create(*parseFile(file)))

with open('cpp.json', 'w') as f:
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