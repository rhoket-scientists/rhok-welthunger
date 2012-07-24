GUI = gui
GEN = gui/gen
TEST = 
PYUIC = pyuic4
PYRCC = pyrcc4
PYTHON = python
PIP = pip

all: test_unit run_no_gui

UI 	:= $(shell cd ${GUI}; ls *.ui)

UIPY = $(UI:%.ui=%.py)

generate_pyqt: gen_ui resources_rc.py

gen_ui: ${UIPY}

${UIPY}:  %.py : ${GUI}/%.ui
	${PYUIC} -o ${GEN}/$@ $<

resources_rc.py: ${GUI}/resources.qrc
	${PYRCC} -o $@ $<

run: gen_ui
	${PYTHON} main.py

run_no_gui:
	${PYTHON} main.py -c

test_unit:
	${PYTHON} -m unittest discover test "*.py"

test_unit_verbose:
	${PYTHON} -m unittest discover test "*.py" -v

req_developer:
	${PIP} install -r devel-req.txt

req_stable:
	${PIP} install -r stable-req.txt

clean:
	@rm -f ${GEN}/*.py
	@rm -f ${GEN}/*.pyc
	@find . -name "*.pyc" -exec rm -rf {} \;
	@touch ${GEN}/__init__.py
