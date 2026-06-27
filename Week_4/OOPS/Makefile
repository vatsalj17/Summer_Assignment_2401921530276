JAVAC = javac
JAVA = java

all: build

build:
	$(JAVAC) *.java

run: build
	@echo "Running Task 1 (ToTestInt)"
	@$(JAVA) ToTestInt
	@echo ""
	@echo "Running Task 2 (InnerClassDemo)"
	@$(JAVA) InnerClassDemo
	@echo ""
	@echo "Running Task 4 (Box3d)"
	@$(JAVA) Box3d
	@echo ""

clean:
	rm -f *.class
