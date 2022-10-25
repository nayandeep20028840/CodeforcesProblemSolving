# // #include <bits/stdc++.h>

# // using namespace std;

# // signed main(signed argc, char* argv[]){
# //     ios_base::sync_with_stdio(false);
# //     cin.tie(NULL);
# //     srand(atoi(argv[1]));

# //     // generate test cases with same format as given in problem

# //     return 0;
# // }

set -e
g++ 1.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer