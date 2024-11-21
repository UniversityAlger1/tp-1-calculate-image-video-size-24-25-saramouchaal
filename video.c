#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored section)
//   durationCredits: duration in seconds of the credits (black-and-white section)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   Total video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the size of one frame
    float coloredFrameSizeBits = (float)(w * h * 24); // 24 bits per pixel for a colored image
    float grayFrameSizeBits = (float)(w * h * 8); // 8 bits per pixel for a black-and-white image

    // Calculate the total number of frames
    int totalColoredFrames = durationMovie * fps;
    int totalGrayFrames = durationCredits * fps;

    // Calculate the total size in bits
    float totalSizeBits = (totalColoredFrames * coloredFrameSizeBits) + 
                          (totalGrayFrames * grayFrameSizeBits);

    // Convert based on the unit parameter
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBits; // Return size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBits / 1024.0f; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBits / (1024.0f * 1024.0f); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBits / (1024.0f * 1024.0f * 1024.0f); // Convert to gigabits
    }

    // If unit is invalid, return 0
    return 0;
}
