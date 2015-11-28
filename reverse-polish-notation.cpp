class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string>op;//符号栈
        vector<string>num;//表达式结果栈
        for(int i=0;i<expression.size();i++)//一遍扫描
        {
            if(expression[i]=="+" || expression[i]=="-")//处理加号、减号
            {
                if(op.size()==0)
                    op.push_back(expression[i]);
                else
                {
                while(op.size()!=0 && (op[op.size()-1]=="*" || op[op.size()-1]=="/" ||op[op.size()-1]=="+" || op[op.size()-1]=="-"))
                {
                    string s=op.back();
                    op.pop_back();
                    num.push_back(s);
                   
                } op.push_back(expression[i]);
                }
                if(op[op.size()-1]=="(")
                {
                    op.push_back(expression[i]);
                }
            }
            else if(expression[i]=="*" || expression[i]=="/")//处理乘号、除号
            {
                 if(op.size()==0)
                    op.push_back(expression[i]);
                else if(op[op.size()-1]=="*" || op[op.size()-1]=="/" )
                {
                    string s=op.back();
                    op.pop_back();
                    num.push_back(s);
                    op.push_back(expression[i]);
                }
                 else if(op[op.size()-1]=="+" || op[op.size()-1]=="-")
                {
                    op.push_back(expression[i]);
                }
                 else if(op[op.size()-1]=="(")
                {
                    op.push_back(expression[i]);
                }
            }
            else if(expression[i]=="(")//处理左括号
            {
                    op.push_back(expression[i]);
            }
            else if(expression[i]==")")//处理右括号
            {
                while(op.back()!="(")
                { 
                    string s=op.back();
                    op.pop_back();
                    num.push_back(s);
                 }
                 op.pop_back();
            }
            else//运算数直接压入表达式结果栈
            {
                num.push_back(expression[i]);
            }
        }
        while(op.size()!=0)//符号栈仍有符号时，将其压入表达式结果栈
        {
            string s=op.back();
            op.pop_back();
            num.push_back(s);
        }
        return num;
    }
};
