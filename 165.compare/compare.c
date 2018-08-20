/*
* This kind of problems is my most hated one
* The algorithm is simple but need lots of work when implementing
* becuase of some people's contribution of tricky test cases!
*/

int compareVersion(char* version1, char* version2) {
    
		//first you need to make two version strings in the same length
		//(that is, they have same amount of dots)
		int ptr1 = 0;
    int ptr2 = 0;
    int dot1 = 0;
    int dot2 = 0;
    while(version1[ptr1] != '\0') {
        if(version1[ptr1] == '.')
            dot1++;
        ptr1++;
    }
    while(version2[ptr2] != '\0') {
        if(version2[ptr2] == '.')
            dot2++;
        ptr2++;
    }
    

		//after they have same length, you need to convert
		//string in each segment to number
		//(be aware of strings like 01 which is actually equal to 1) 
    char *temp_ver = malloc(sizeof(char) * 1000);
    int ver_size = 0;
    if(dot1 > dot2) {
        for(int i = 0; i < ptr2; i++) {
            temp_ver[i] = version2[i];
            ver_size++;
        }
        for(int i = 0; i < (dot1 - dot2); i++ ) {
            temp_ver[ver_size] = '.';
            ver_size++;
            temp_ver[ver_size] = '0';
            ver_size++;
        }
        temp_ver[ver_size] = '\0';
        ver_size++;
        version2 = temp_ver;
    } else if(dot1 < dot2) {
        for(int i = 0; i < ptr1; i++) {
            temp_ver[i] = version1[i];
            ver_size++;
        }
        for(int i = 0; i < (dot2 - dot1); i++ ) {
            temp_ver[ver_size] = '.';
            ver_size++;
            temp_ver[ver_size] = '0';
            ver_size++;
        }
        temp_ver[ver_size] = '\0';
        ver_size++;
        version1 = temp_ver;
    }
    
    ptr1 = 0;
    ptr2 = 0;
    while(true) {
        int temp_ptr1 = ptr1;
        int temp_ptr2 = ptr2;
        while(version1[temp_ptr1] != '.' && version1[temp_ptr1] != '\0') {
            temp_ptr1++;
        }
        while(version2[temp_ptr2] != '.' && version2[temp_ptr2] != '\0') {
            temp_ptr2++;
        }

        int vA = 0;
        int multi = 1;
        for(int i = temp_ptr1 - 1; i >= ptr1; i--) {
            int tA = version1[i] - '0';
            vA += tA * multi;
            multi *= 10;
        }
        int vB = 0;
        multi = 1;
        for(int i = temp_ptr2 - 1; i >= ptr2; i--) {
            int tB = version2[i] - '0';
            vB += tB * multi;
            multi *= 10;
        }

        if(vA > vB) {
            return 1;
        } else if(vA < vB) {
            return -1;
        } else {
            //finally, you need to deal with the cases of '.' and '\0'
            if(version1[temp_ptr1] == '\0' && version2[temp_ptr2] == '\0') {
                if(vA == vB)
                    return 0;
            }
            if(version1[temp_ptr1] == '\0') {
                return -1;
            }
            if(version2[temp_ptr2] == '\0') {
                return 1;
            }
            ptr1 = temp_ptr1 + 1;
            ptr2 = temp_ptr2 + 1;
        }
    }
    return 0;
}
