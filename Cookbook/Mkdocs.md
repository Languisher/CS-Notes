# Mkdocs

## Installation

```python
pip install mkdocs
pip install mkdocs-material
pip install https://github.com/mitya57/python-markdown-math/archive/master.zip`
```

## Create, Server and Publishment

- Create a projet: `mkdocs new [filename]`

- Render to a site: `mkdocs serve`

- Publish: `mkdocs gh-deploy`


## Code

- **Code Naming, Code Highlighting, Line Numeration**: By adding `title="name" linenums="1" hl_lines="index"` at the right of the first ```, example : 

```py title="first.py" linenums="1" hl_lines="2"
print("Hello World")
# Yes, it works!
```

## Template for mkdocs.yml
```yaml
site_name: Test # Change here

nav:
    - Home: 'index.md'
    - 'Cookbooks': 
      - 'Mkdocs': 'Cookbooks/Mkdocs.md'

theme: 
  name: material
  features:
    - naviagation.tabs
    - naviagation.sections
    - toc.integrate
    - navigation.top
    - search.suggest
    - search.highlight
    - content.tabs.link
    - content.code.annotation
    - content.code.copy
  language: en
  palette:
    - scheme: default
      toggle:
        icon: material/toggle-switch-off-outline
        name: Switch to dark mode
      primary: teal
      accent: purple
    - scheme: slate
      toggle:
        icon: material/toggle-switch
        name: Switch to light mode
      primary: teal
      accent: lime

extra:
  social:
    - icon: fontawesome/brands/github-alt
      link: https://github.com/Languisher # Change to your github link

copyright: | # Change based on your own personal information
  &copy; 2023 <a href="https://github.com/Languisher"  target="_blank" rel="noopener">Brandon Lin</a>

extra_javascript: 
    - https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML

markdown_extensions:
    - pymdownx.highlight:
        anchor_linenums: true
    - pymdownx.inlinehilite
    - pymdownx.snippets
    - admonition
    - pymdownx.arithmatex:
        generic: true
    - footnotes
    - pymdownx.details
    - pymdownx.superfences
    - pymdownx.mark
    - attr_list
    - mdx_math
```

Explications:

- The `nav` configuration setting in your mkdocs.yml file defines which pages are included in the global site navigation menu as well as the structure of that menu. If not provided, the navigation will be automatically created by discovering all the Markdown files in the documentation directory.



## References
- ![Basic Tutorial](https://www.mkdocs.org/user-guide/)
- ![Material Tutorial](https://www.youtube.com/watch?v=Q-YA_dA8C20)
- ![Problems with Mathjax](https://stackoverflow.com/questions/27882261/mkdocs-and-mathjax)