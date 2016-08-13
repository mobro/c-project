# c-project

<b>Code formatting</b><br>
copy the .indent.pro file into the root folder, so indent will use this profile when called in vim via 1G!Gindent to format your C File.

<b>Code snippets</b><br>
If you want to insert blocks of code which you often use with a shortcut. Using c-support.vim https://lug.fh-swf.de/vim/vim-c/c-hotkeys.pdf the commands allways start with \

<b>NERDTree</b><br>
Use a file browser inside vim. Open file in horizontal split window is i
http://www.usevim.com/2012/07/18/nerdtree

<b>Using CMake</b><br>
CMakeLists.txt is the configuration file. Use cmake . and than make to generate the executable.

<b>Using GitHub</b><br>
Use the SSH link and not the https link, generate a SSH key and add it to the github account.

<b>Auto completion</b><br>
If you want to have a auto completion inside vim use YouCompleteMe.

<b>Jumping to definitions, declarations etc.</b><br>
Use exuberant-ctags, go to the project root folder and run ctags -R --exclude=.git .

<b>Search in files</b><br>
grep -rnw '/path/to/somewhere' -e "pattern"

<b>Bash</b><br>
Use the history -a command in the bash to see which commands you were using.<br>
Use Ctrl -l to clear the terminal.<br>
Use !x to search in the command history for x command.<br>

<b>ZSH</b><br>
Using the adam2 zshell
