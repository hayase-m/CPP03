NAME = diamondtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP
INCLUDES = -Iinclude

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

SRCDIR = src
OBJDIR = objs
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
RM = rm -rf

all: $(NAME)

-include $(OBJS:.o=.d)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
