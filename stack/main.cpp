#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> S, st,sp;
    stack<int> si,sit;
    int x, y,temp;
    string str;
    while(1)
    {
        //读取数据
        while(((cin>>str)==cin)&&(str[0]!='='))
        {
            //筛选数据，符号、数字分两个栈存放
            for(int n = 0; str[n]!='='; n++)
            {
                if(isdigit(str[n]))
                {
                    st.push((int)str[n]);
                }
                else if(str[n]==')')
                {
                    while(S.top()!='(')
                    {
                        st.push(S.top());
                        S.pop();
                    }
                    S.pop();
                }
                else if((str[n]=='+')||(str[n]=='-'))
                {
                    if(S.empty()!=1)
                    {
                        if((S.top()=='*')||(S.top()=='/'))
                        {
                            while(S.empty()!=1)
                            {
                                if(S.top()=='(')
                                    break;
                                st.push(S.top());
                                S.pop();
                            }
                        }
                    }
                    S.push(str[n]);
                }
                else
                    S.push(str[n]);
            }
            while(S.empty()!=1)
            {
                st.push(S.top());
                S.pop();
            }

            sp.push('=');
            while(st.empty()!=1)
            {
                S.push(st.top());
                sp.push(st.top());
                st.pop();
            }
            //对后缀表达式进行求值
            while(S.empty()!=1)
            {
                if(!isdigit(S.top()))
                {
                    y=si.top();
                    si.pop();
                    x=si.top();
                    si.pop();
                    if(S.top()=='+')
                    {
                        si.push(x+y);
                    }

                    else if (S.top()=='-')
                    {
                        si.push(x-y);
                    }

                    else if (S.top()=='*')
                        si.push(x*y);
                    else if (S.top()=='/')
                        si.push(x/y);
                    S.pop();
                }
                else
                {
                    si.push(S.top()-48);
                    S.pop();
                }
            }
            while(!si.empty())
            {
                sit.push(si.top());
                si.pop();
            }
        }
        //输出结果
        cout<<endl;
        while(!sp.empty())
        {
            cout<<sp.top();
            if (sp.top()=='=')
            {
                cout<<endl<<sit.top()<<endl;
                sit.pop();
            }
            sp.pop();
        }
    }
}




