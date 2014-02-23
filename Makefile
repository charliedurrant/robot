# Builds all the projects in the solution...
.PHONY: all_projects
all_projects: robot 

# Builds project 'robot'...
.PHONY: robot
robot: 
	make --directory="robot/" --file=robot.makefile

# Cleans all projects...
.PHONY: clean
clean:
	make --directory="robot/" --file=robot.makefile clean

