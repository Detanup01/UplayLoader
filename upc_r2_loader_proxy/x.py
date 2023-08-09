normal = """
        PRINT_DEBUG("%s (Before): __PRINTHERE__\\n", __FUNCTION__,__REPLACEME__);
	GET_PROXY_FUNC(__FUNC_NAME__);
	auto result = proxyFunc(__REPLACEME__);
	PRINT_DEBUG("%s (After): __PRINTAFTER_\\n", __FUNCTION__, result, __PRINT_EX__);
	return result;
"""
void_replace = """
	PRINT_DEBUG("%s __PRINTHERE__\\n", __FUNCTION__,__REPLACEME__);
	GET_PROXY_FUNC(__FUNC_NAME__);
	proxyFunc(__REPLACEME__);
"""

dic = {
    "void *": "%p",
    "void* ": "%p",
    "void*": "%p",
    "char *": "%s",
    "char*": "%s",
    "char **": "%s",
    "unsigned": "%u",
    "unsigned *": "%u",
    "Result" : "%u",
    "InitResult" : "%u",
    "bool": "%d",
    "bool *": "%d",
    "float *": "%g",
    "int": "%i",
    "int *": "%i"
    }

def handle_void(x):
        y = x[len(xplit[0])+1:]
        funcname = y.split("(")[0]
        n = "EXPORT " + x + "\n{"
        n = n + void_replace
        n = n.replace("__FUNC_NAME__",funcname)
        yeet = x[len(xplit[0])+1+len(funcname)+1:-1]
        if yeet == "":
            n = n.replace(" __PRINTHERE__","")
            n = n.replace(",__REPLACEME__","")
            n = n.replace("__REPLACEME__","")
        else:
            params = yeet.split(", ")
            torep_str = " "
            funcparams = ""
            for par in params:
                if par.__contains__(" *"):
                    lstar = par.find(" *")
                    torep = dic[par[0:lstar+2]]
                    torep_str = torep_str + torep + " "
                    funx = par[lstar+2:]
                    funcparams = funcparams + ", " + funx
                    
                else:
                    torep = dic[par[0:len(par.split(" ")[0])]]
                    torep_str = torep_str + torep + " "
                    funx = par[len(par.split(" ")[0])+1:]
                    funcparams = funcparams + ", " + funx
            n = n.replace(" __PRINTHERE__",torep_str)
            funcparams = funcparams[1:] + " "
            n = n.replace("__REPLACEME__",funcparams)
        n += "}\n"
        print(n)


def handle_oneparam(yeet,xplit,n):
    torep_str = " "
    funcparams = ""
    if yeet.__contains__(" *"):
        lstar = yeet.find(" *")
        torep = dic[yeet[0:lstar+2]]
        funx = yeet[lstar+2:]
        torep_str = torep_str + torep + " "
        funcparams = funcparams + ", " + funx
    else:
        torep = dic[yeet[0:len(yeet.split(" ")[0])]]
        funx = yeet[len(yeet.split(" ")[0])+1:]
        torep_str = torep_str + torep + " "
        funcparams = funcparams + ", " + funx
    n = n.replace(", __PRINT_EX__","")
    n = n.replace(" __PRINTHERE__",torep_str)
    funcparams = funcparams[1:] + " "
    n = n.replace("__REPLACEME__",funcparams)
    n += "}\n"
    n = n.replace("__PRINTAFTER_",dic[xplit[0]])
    print(n)

f = open("funcs.txt","r")
for x in f:
    x = x.replace("\n","")
    #print(x)
    xplit = x.split(" ")
    if (xplit[0] == "void"):
        handle_void(x)
        i = 0
    else:
        #print(xplit[0])
        y = x[len(xplit[0])+1:]
        funcname = y.split("(")[0]
        n = "EXPORT " + x + "\n{"
        n = n + normal
        n = n.replace("__FUNC_NAME__",funcname)
        yeet = x[len(xplit[0])+1+len(funcname)+1:-1]
        if yeet.__contains__(","):
            torep_str = " "
            funcparams = ""
            params = yeet.split(", ")
            for par in params:
                if par.__contains__(" *"):
                    lstar = par.find(" *")
                    torep = dic[par[0:lstar+2]]
                    torep_str = torep_str + torep + " "
                    funx = par[lstar+2:]
                    funcparams = funcparams + ", " + funx
                    
                else:
                    torep = dic[par[0:len(par.split(" ")[0])]]
                    torep_str = torep_str + torep + " "
                    funx = par[len(par.split(" ")[0])+1:]
                    funcparams = funcparams + ", " + funx
            n = n.replace(" __PRINTHERE__",torep_str)
            funcparams = funcparams[1:] + " "
            n = n.replace("__REPLACEME__",funcparams)
            n = n.replace("__PRINTAFTER_",dic[xplit[0]] + " " + torep_str)
            n = n.replace("__PRINT_EX__",funcparams)
            n += "}\n"
            print(n)
        else:
            i = 0
            handle_oneparam(yeet,xplit,n)
        
        
