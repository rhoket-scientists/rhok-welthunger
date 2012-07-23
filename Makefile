GUI = gui
GEN = gui/gen
TEST = 
PYUIC = pyuic
PYRCC = pyrcc4
PYTHON = python
PIP = pip

all: run_tests gen_ui resources_rc.py

UI 	:= $(shell cd ${GUI}; ls *.ui)

UIPY = $(UI:%.ui=%.py)

gen_ui: ${UIPY}

${UIPY}:  %.py : ${GUI}/%.ui
	${PYUIC} -o ${GEN}/$@ $<

resources_rc.py: ${GUI}/resources.qrc
	${PYRCC} -o $@ $<

run_tests:
	${PYTHON} -m unittest discover test "*.py" -v

req_developer:
	${PIP} install -r devel-req.txt

req_stable:
	${PIP} install -r stable-req.txt

clean:
	rm -f ${GEN}/*.py
	rm -f ${GEN}/*.pyc
	touch ${GEN}/__init__.py
