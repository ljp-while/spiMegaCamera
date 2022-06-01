# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))

import subprocess, os

def configureDoxyfile(input_dir, output_dir):
    with open('Doxyfile.in', 'r') as file :
        filedata = file.read()

    filedata = filedata.replace('@DOXYGEN_OUTPUT_DIR@', output_dir)

    with open('Doxyfile', 'w') as file:
        file.write(filedata)

# Check if we're running on Read the Docs' servers
# read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'
read_the_docs_build = True

breathe_projects = {}

if read_the_docs_build:
    input_dir = '../spiCamera'
    output_dir = 'build'
    configureDoxyfile(input_dir, output_dir)
    subprocess.call('doxygen', shell=True)
    breathe_projects['CatCutifier'] = output_dir + '/xml'


# -- Project information -----------------------------------------------------

project = 'SPICamera'
copyright = '2021, Arducam'
author = 'Arducam'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'breathe',
    "sphinx.ext.intersphinx",
    "sphinx.ext.autosectionlabel",  # https://github.com/sphinx-doc/sphinx/issues/7697 wait for this and implement
    "sphinx_rtd_theme",
]

# Breathe Configuration
breathe_default_project = "CatCutifier"
breathe_implementation_filename_extensions=['.h']
# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
#exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

html_theme_options = {
    "collapse_navigation" : False
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

html_css_files = [
    ('https://www.arducam.com/wp-content/uploads/2022/03/header.518f04c1.css', {"type": "module"}),
    "css/arheader.css",
]

html_js_files = [
    ("https://www.arducam.com/wp-content/uploads/2022/03/vendor.9b5502a0.js", {"type": "module"}),
    ("https://www.arducam.com/wp-content/uploads/2022/03/header.518f04c1.js", {"type": "module"}),
    "js/navbar.js"
]