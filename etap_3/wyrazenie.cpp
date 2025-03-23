#include <bits/stdc++.h>
using namespace std;

bool is_vovel(char x){
    if(x=='A' || x=='I' || x=='O' || x=='U' || x=='Y' || x=='E'){
        return true;
    }
    return false;
}

bool validate_string(string s){
    int len = s.length();

    int opens = 0;
    int closes = 0;

    if(s[0] == '+' || s[0] == '*' || s[0] == ')'){
        cout << "ERROR0";
        return false;
    }

    for(int i=0;i<len-1;i++){
        if(s[i] == '('){
            opens++;
            if(s[i+1]==')' || s[i+1]=='*' || s[i+1]=='+'){
                cout << "ERROR1";
                return false;
            }
        }

        else if(s[i] == ')'){
            closes++;
            if(s[i+1] != '*' && s[i+1] != '+' && s[i+1] != ')'){
                cout << "ERROR2";
                return false;
            }
        }

        else if(s[i] == '+' || s[i] == '*'){
            if(s[i+1] == '*' || s[i+1]== '+' || s[i+1]==')'){
                cout << "ERROR3";
                return false;
            }
        }

        else{
            if(s[i+1] != '*' && s[i+1]!= '+' && s[i+1]!=')'){
                cout << s[i] << " - " << s[i+1] << endl;

                cout << "ERROR4";
                return false;
            }
        }
    }

    if(s[len-1] == ')') closes++;

    if(opens != closes){
        cout << "ERROR5";
        return false;
    }

    return true;
}

char calc_sent(string sent){
    char v_1, v_2, operation;
    if (sent.length() == 5){
        v_1 = sent[1];
        v_2 = sent[3];
        operation = sent[2];
    }else if(sent.length() == 3){
        v_1 = sent[0];
        v_2 = sent[2];
        operation = sent[1];
    }

    if(v_1 == '(' && v_2 == ')') return operation;

    if(operation=='+'){
        if(is_vovel(v_1) && is_vovel(v_2)) return min(v_1, v_2);
        else if(is_vovel(v_1) && !is_vovel(v_2)) return v_1;
        else if(!is_vovel(v_1) && is_vovel(v_2)) return v_2;
        else if(!is_vovel(v_1) && !is_vovel(v_2)) return max(v_1, v_2);
    }

    if(operation=='*'){
        if(is_vovel(v_1) && is_vovel(v_2)) return max(v_1, v_2);
        else if(is_vovel(v_1) && !is_vovel(v_2)) return v_2;
        else if(!is_vovel(v_1) && is_vovel(v_2)) return v_1;
        else if(!is_vovel(v_1) && !is_vovel(v_2)) return min(v_1, v_2);
    }
}

int main(){
    string s;
    cin >> s;

    bool is_good = validate_string(s);
    if(!is_good){
        return 0;
    }

    while(true){
        int len = s.length();
        int start = -3;
        bool found = false;

        for(int i=0;i<len;i++){
            if(s[i]=='(') start = i;
            if(s[i]==')'){
                if(start==-3){
                    cout << "ERROR";
                    return 0;
                }
                if(i - start - 1 == 3){
                    if(i==len-1) s = s.substr(0,start) + calc_sent(s.substr(start, 5));
                    else s = s.substr(0,start) + calc_sent(s.substr(start, 5)) + s.substr(i+1, len - i - 1);

                    found = true;
                    break;
                } else if(i - start - 1 == 1){
                    if(i==len-1) s = s.substr(0,start) + s[i-1];
                    else s = s.substr(0,start) + s[i-1] + s.substr(i+1, len - i - 1);

                    found = true;
                    break;
                }else{
                    start = -2;
                }
            }
        }
        if(found) continue;

        for(int i=0;i<len-2;i++){
            if(s[i]!='*' && s[i]!='+' && s[i]!='(' && s[i]!=')'){
                if(s[i+1] == '*'){
                    if(s[i+2]!='*' && s[i+2]!='+' && s[i+2]!='(' && s[i+2]!=')'){
                        if(i==len-3) s = s.substr(0,i) + calc_sent(s.substr(i, 3));
                        else s = s.substr(0,i) + calc_sent(s.substr(i, 3)) + s.substr(i+3, len - i - 3);

                        found = true;
                    }
                }
            }
        }
        if(found) continue;

        for(int i=0;i<len-2;i++){
            if(s[i]!='*' && s[i]!='+' && s[i]!='(' && s[i]!=')'){
                if(s[i+1] == '+'){
                    if(s[i+2]!='*' && s[i+2]!='+' && s[i+2]!='(' && s[i+2]!=')'){
                        if(i==len-3) s = s.substr(0,i) + calc_sent(s.substr(i, 3));
                        else s = s.substr(0,i) + calc_sent(s.substr(i, 3)) + s.substr(i+3, len - i - 3);

                        found = true;
                    }
                }
            }
        }
        if(found) continue;

        cout << s << endl;
        break;
    }

    return 0;
}
