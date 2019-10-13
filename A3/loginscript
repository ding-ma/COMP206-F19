# .bashrc

# Source global definitions
if [ -f /usr/socs/Profile ]; then
        . /usr/socs/Profile
fi

# User specific aliases and functions
alias ll="ls -la --color=auto"
alias lf="ls -F"
alias ls='ls --color=auto'
alias grep='grep --color=auto'
alias lr="ls -R"

#### 
# What is bellow is for Assignment 3 COMP 206.

# alias
alias la="ls -la"

# print name
name=$(whoami)
echo "Welcome $name to SOCS BASH!"

# set memory size to 10
export HISTSIZE=10

#sets prompt
# \W is for only the current directory and \w is for the entire path
# question was not clear about it

PS1="\u, \W: "

# finding my friend
who | grep loudni

#Extra feature, alias
alias ..="cd .."
alias ...="cd ../.."
