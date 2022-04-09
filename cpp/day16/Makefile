all: compile_agent compile_user

compile_agent: agent.cpp lib/substring.cpp
	g++ -Wall -std=gnu++14 -g agent.cpp lib/substring.cpp -o agent

compile_user: user.cpp lib/substring.cpp
	g++ -Wall -std=gnu++14 -g user.cpp lib/substring.cpp -o user

run_agent:
	./agent

run_user:
	./user
