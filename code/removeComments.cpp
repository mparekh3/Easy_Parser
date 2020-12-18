/* We will be using only removeComments function for our main.cpp file as we have decided not to remove spaces from our file(use them to seperate tokens)*/


string removeComments(string prgm) 
{ 
    int n = prgm.length(); 
    string res; 
   
    bool s_cmt = false; 
    bool m_cmt = false; 
  
    for (int i=0; i<n; i++) 
    {  //for checking ending of comments section
        if (s_cmt == true && prgm[i] == '\n') 
            s_cmt = false; 
   
        else if  (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/') 
            m_cmt = false,  i++; 
  
        else if (s_cmt || m_cmt) 
            continue; 
   // For checking beginning of comments
        else if (prgm[i] == '/' && prgm[i+1] == '/') 
            s_cmt = true, i++; 
        else if (prgm[i] == '/' && prgm[i+1] == '*') 
            m_cmt = true,  i++; 
  
        else  res += prgm[i]; 
    } 
    return res; 
} 
 
int main() 
{ 
    string prgm = "   /* Test program */ \n"
                  "   int main()  \n"
                  "   {           \n"
                  "      // variable declarations \n"
                  "      int a, b, res;    \n"
                  "      /* Random  \n"
                  "          comments     \n"
                  "          for mutiple    \n"
                  "        */     case \n"
                  "      res = a * b;       \n"
                  "   }           \n"; 
    cout << "Given Program \n"; 
    cout << prgm << endl; 
    cout << " Modified Program "; 
    cout << removeComments(prgm); 
    return 0; 
}