GUI = gui
GEN = gui/gen
PYUIC = pyuic
PYRCC = pyrcc4

all: gen_ui resources_rc.py

UI 	:= $(shell cd ${GUI}; ls *.ui)

UIPY = $(UI:%.ui=%.py)

gen_ui: ${UIPY}

${UIPY}:  %.py : ${GUI}/%.ui
	${PYUIC} -o ${GEN}/$@ $<

resources_rc.py: ${GUI}/resources.qrc
	${PYRCC} -o $@ $<

clean:
	rm -f ${GEN}/*.py
	rm -f ${GEN}/*.pyc
	touch ${GEN}/__init__.py
