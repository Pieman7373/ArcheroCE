# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= Archero
COMPRESSED  ?= YES
ARCHIVED    ?= YES
ICON        ?= ArcheroCEicon.png
DESCRIPTION ?= "Terrible Archero clone"

# ----------------------------

SRCDIR ?= src
OBJDIR ?= obj
BINDIR ?= bin
GFXDIR ?= src/gfx

include $(CEDEV)/include/.makefile
