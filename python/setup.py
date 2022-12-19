from distutils.core import setup
from Cython.Build import cythonize

setup(
    ext_modules = cythonize("cython_module.pyx",language_level = "3")
) #language_level specifies that we are using python 3
