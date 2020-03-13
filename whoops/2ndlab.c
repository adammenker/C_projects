int returnGrade(int** scores, int** gradeCutoff, int row);

int main(void){
    int x;

    x = returnGrade(a, b, c);
}



int returnGrade(int** scores, int** gradeCutoff, int row){
    int grade_A = gradeCutoff[row][0];
    int grade_B = gradeCutoff[row][1];
    int grade_C = gradeCutoff[row][2];
    int grade_D = gradeCutoff[row][3];



    if(gradeCutoff[0][row] > grade_A){
        return 1;
    }
    else if(gradeCutoff[0][row] > grade_B){
        return 2;
    }
    else if(gradeCutoff[0][row] > grade_C){
        return 3;
    }
    else if(gradeCutoff[0][row] > grade_D){
        return 4;
    }

    
    
    



    int grade_B = gradeCutoff[1][row];
    int grade_C = gradeCutoff[2][row];
    int grade_D = gradeCutoff[3][row];
}