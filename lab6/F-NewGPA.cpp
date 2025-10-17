/*
KBTU introduces new GPA calculation system. You’re given n students, their marks and number of credits for their subjects. Sort them by total GPA. It is calculated as sum(g_i * c_i) / sum(c_i), where m - student’s number of subjects, g_i, c_i - GPA and number of credits for i-th subject respectively. GPA scale is given in the notes.

Input format
First line contains one integer n (1 <= n <= 10^5). Each of the next n lines contains information about the i-th student: his lastname, firstname, an integer m_i - number of subjects for this student, then m_i marks and number of credits for each subject.

Output format
You should print sorted list of students. Each student should be printed in the following format: lastname, firstname, GPA. First, sort them by overall GPA, if it’s equal, sort by lastname, then by firstname. GPA should be printed with three digits after decimal point.

Examples
Input
5
Issenbayev Yernur 4 A 4 D+ 2 B 3 A+ 4
Yermekbayeva Diana 3 A+ 4 B+ 3 B 1
Kadyrov Asman 2 A+ 4 A+ 4
Stepanenko Ivan 3 C+ 3 F 1 A+ 5
Bissimbayev Arystan 3 A+ 4 A+ 5 D 1

Output
Stepanenko Ivan 3.056
Issenbayev Yernur 3.308
Yermekbayeva Diana 3.688
Bissimbayev Arystan 3.700
Kadyrov Asman 4.000

Notes
A+	4.00
A	3.75
B+	3.50
B	3.00
C+	2.50
C	2.00
D+	1.50
D	1.00
F	0

*/


#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct person{
    string f_name;
    string l_name;
    double gpa;
};


bool cmp(person a, person b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.l_name != b.l_name) return a.l_name < b.l_name;
    return a.f_name < b.f_name;
}


int main() {
    int n;
    cin >> n;

    person result[100001];

    for (int i = 0; i < n; ++i) {
        cin >> result[i].l_name >> result[i].f_name;

        int m;
        cin >> m;

        double sum_gc = 0;
        double sum_c = 0;

        for (int j = 0; j < m; ++j) {
            string g;
            int c;
            cin >> g >> c;

            if(g == "A+") sum_gc += (4.0 * c);
            if(g == "A") sum_gc += (3.75 * c);
            if(g == "B+") sum_gc += (3.5 * c);
            if(g == "B") sum_gc += (3.0 * c);
            if(g == "C+") sum_gc += (2.5 * c);
            if(g == "C") sum_gc += (2.0 * c);
            if(g == "D+") sum_gc += (1.5 * c);
            if(g == "D") sum_gc += (1.0 * c);
            if(g == "F") sum_gc += (0 * c);

            sum_c += c;
            
        }

        double total_gpa = sum_gc / sum_c;
        result[i].gpa = total_gpa;
    }

    sort(result, result + n, cmp);

    
    for (int i = 0; i < n; ++i) {
        cout.precision(3);
        cout << result[i].l_name << " " << result[i].f_name << " " << fixed << result[i].gpa << endl;
    }
}