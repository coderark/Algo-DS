#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
    int res=-1;
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket br={next, position};
            //cout<<br.type<<' '<<br.position<<endl;
            opening_brackets_stack.push(br);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
                res=position;
                break;
            }
            else{
                Bracket br=opening_brackets_stack.top();
                //cout<<br.type<<' '<<br.position<<endl;
                opening_brackets_stack.pop();
                if(!br.Matchc(next)){
                    res=position;
                    break;
                }
            }

        }
    }
    if(res==-1){
        Bracket br={' ', -1};
        while(!opening_brackets_stack.empty()){
            br=opening_brackets_stack.top();
            opening_brackets_stack.pop();
        }
        if(br.position==-1){
            cout<<"Success"<<endl;
        }
        else{
            cout<<(br.position+1)<<endl;
        }
    }
    else{
        cout<<(res+1)<<endl;
    }

    return 0;
}
