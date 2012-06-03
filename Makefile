CXXFLAGS+=$(shell pkg-config opencv --cflags) -Wall

LDFLAGS+=$(shell pkg-config opencv --libs)
 
SRC_FILES=$(shell find . -iname "*.cpp")
HDR_FILES=$(shell find . -iname "*.h")
OBJ_FILES=$(SRC_FILES:%.cpp=%.o)
DEP_FILES=$(SRC_FILES:%.cpp=%.d)
 
EXENAME=app
 
all: $(EXENAME)
 
%.d: %.cpp
		$(CXX) -MM $(CXXFLAGS) $< > $@
 
$(EXENAME): $(OBJ_FILES) $(HDR_FILES)
		$(CXX) -g -o $@ $(OBJ_FILES) $(LDFLAGS)

clean:
		$(RM) $(OBJ_FILES) $(DEP_FILES)
		$(RM) $(EXENAME)
 
run: $(EXENAME)
		./$(EXENAME)
 
.PHONY: all clean run
 
include $(DEP_FILES)
