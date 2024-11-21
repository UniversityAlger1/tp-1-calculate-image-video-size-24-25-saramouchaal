#include <stdio.h>

// Function 
float grayScaleImage(int w, int h) {
    // Calculate the size (each pixel is 1 byte)
    float size = (float)(w * h);
    return size; // Return the size in bytes
}

int main() {
    int width, height;

    // Testing
    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Calculate the size
    float size = grayScaleImage(width, height);

    // Display the result
    printf("The size of the grayscale image is: %.0f bytes\n", size);

    return 0;
}
