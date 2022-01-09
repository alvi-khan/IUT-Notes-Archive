import os
import urllib.parse


DOWNLOAD_BASE = "https://minhaskamal.github.io/DownGit/#/home?url=https:%2F%2Fgithub.com%2Falvi-khan%2FIUT-Notes-Archive%2Ftree%2Fmain%2F"


def create_url(path, file):
    filename = os.path.splitext(file)[0]
    url = ""
    with open(f"{path}/{file}", "r") as infile:
        for line in infile:
            if (line.startswith('URL')):
                url = line[4:]
                break
    
    return f"[{'🌎 '}{filename}]({url})"


def create_file_link(path, file):
    filename = file
    extension = os.path.splitext(file)[1]
    if extension in [".docx", ".pdf", ".png", ".jpg"]:
        filename = os.path.splitext(file)[0]
    
    path = "/".join(path.split("/")[3:])
    file = f"./{path}/{file}"
    file = urllib.parse.quote(file.encode("utf-8"))
    
    icon = ""
    if extension in [".txt", ".docx", ".doc", ".pdf", ".pptx", ".xlsx"]:
        icon = "📄 "
    if extension == ".zip":
        icon = "📦 "
    if extension in [".svg", ".png", ".jpg", ".tif"]:
        icon = "🖼️ "
    if extension in ['.c', '.h', '.cpp', '.java', '.py', '.dwg', '.gns3', '.ipynb', '.pdsprj', '.sql', '.m', '.psimsch', '.sh', '.asm', '.pkt', '.pka', '.tex', '.sty', '.bib', '.out', '.l', '.y']:
        icon = "💻 "
    
    return f'[{icon}{filename}]({file})'


def process_folder(name, path, level):
    download_link = urllib.parse.quote(f"{path[2:]}".encode("utf-8"))
    if (level == 1):
        text = f"{'#' * level} {name} [{'(Download ⬇️)'}]({DOWNLOAD_BASE}/{download_link})"
    else:
        text = f"{'#' * level} [{'⬇️ '}]({DOWNLOAD_BASE}/{download_link}){name}"

    subfolders = []
    for file in os.listdir(path):
        if os.path.isdir(f"{path}/{file}"):
            subfolders.append(file)
        elif file == "README.md":
            continue
        elif file.endswith(".url"):
            text = text + f"\n- {create_url(path, file)}"
        else:
            text = text + f"\n- {create_file_link(path, file)}"
    
    for folder in subfolders:
        text = text + "\n\n" + process_folder(folder, f"{path}/{folder}", level + 1)
    
    return text


for semester in os.listdir():
    if not semester.startswith("Semester "):
        continue
    
    semester = f"./{semester}"
    
    for course in os.listdir(semester):
        with open(f"{semester}/{course}/README.md", 'w', encoding="utf-8") as f:
            text = f'<link href="../../style.css" rel="stylesheet">\n\n'
            text = text + process_folder(course, f"{semester}/{course}", 1)
            f.write(text)
