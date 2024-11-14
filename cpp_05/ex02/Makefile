NAME = aform
CC = c++
CFLAGS = -std=c++98
RM = rm -rf

SRC = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJDIR = obj

OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME).dSYM


fclean: clean
	@$(RM) $(NAME)


re: fclean all

run: all
	@./$(NAME)


.PHONY: all clean fclean re run
