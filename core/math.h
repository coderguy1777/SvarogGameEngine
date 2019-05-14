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

float pow2(float num) {
    return num * num;
}

int pow2(int num) {
    return num * num;
}

double pow2(double num) {
    return num * num;
}