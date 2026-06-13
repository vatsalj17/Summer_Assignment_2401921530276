JC = javac
JFLAGS = -d .
SOURCES = music/Playable.java music/string/Veena.java music/wind/Saxophone.java live/Test.java
MAIN = live.Test

all: $(SOURCES)
	$(JC) $(JFLAGS) $(SOURCES)

run: all
	java $(MAIN)

clean:
	find . -name "*.class" -delete
