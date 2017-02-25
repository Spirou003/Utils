import os

"""
The directory Utils is shared between all my project, then I want it to not be dupplicated.
So I use junction for Windows which work fine. For Linux, I use symlink but Git refuse to
work with these, thus I have to choose:
- create dupplicates of all my repository Utils into each project (and maybe create conflicting versions)
- find another way to work all time with the common code of Utils

I choose the second:
- during my work, I use symlink and don't care
- for commits, I dupplicate the content into Utils2
- and this script will switch the names of the symlink and the copy
"""

os.rename("src/Utils", "src/Utils3")
os.rename("src/Utils2", "src/Utils")
os.rename("src/Utils3", "src/Utils2")
