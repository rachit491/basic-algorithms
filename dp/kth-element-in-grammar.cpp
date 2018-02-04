//kth element in grammar

//Final
int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
    else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
}

//Try 1

int kthGrammar(int N, int K) {
    if(K > pow(2,N-1)) 
        return -1;
    
    string str = "0", str2 = "";
    for(int j=0; j<N-1; j++) {
        str2 = "";
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '0') {
                str2 += str[i];
                str2 += "1";
            }
            if(str[i] == '1') {
                str2 += str[i];
                str2 += "0";
            }
        }
        str = str2;
    }
    
    
    return str[K-1] == '0' ? 0 : 1;
}

//Try 2

string flip(char c) {
    return (c == '0') ? "1": "0";
}

int kthGrammar(int N, int K) {
    if(K > pow(2,N-1)) 
        return -1;
    
    string str = "0", str2 = "";
    for(int i=1; i<str.size(); i++) {
        str += flip(str[i-1]);
        if(K == str.size()) {
            return str[(K-1)] == '0' ? 0 : 1;
        }
    }
    
    
    
    return str[(K-1)] == '0' ? 0 : 1;
}