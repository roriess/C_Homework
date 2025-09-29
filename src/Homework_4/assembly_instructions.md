Assembly instructions

1) Clone the project \
git clone https://github.com/roriess/C_Homework \
2) Go to the repository \
cd C_Homework
4) If Homework_4 is in the main branch, skip this step \
git checkout Homework_4
5) Go to the folder Homework_4 \
cd src/Homework_4
6) Build a project \
as --64 -o optimal_sorting.o optimal_sorting.s \
gcc -m64 -Wall -Wextra -pedantic -std=c11 -o sorter main.c optimal_sorting.o
7) Launch the project \
./sorter
