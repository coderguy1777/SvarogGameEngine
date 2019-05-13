float square(int fac, float num) {
    float result = 0.0f;
    for(int i = 0; i < fac; i++) {
        result += num * num;
    }
    return result;
}

double square(int fac, double num) {
    double result = 0.0;
    for(int i = 0; i < fac; i++) {
        result += num*num;
    }
    return result;
}

int square(int fac, int num) {
    int result = 0;
    for(int i = 0; i < fac; i++) {
        result += num * num;
    }
    return result;
}