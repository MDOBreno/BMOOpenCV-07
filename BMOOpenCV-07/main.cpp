//
//  main.cpp
//  BMOOpenCV-07
//
//  Created by Breno Medeiros on 31/03/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

const int fps = 20;

//Pode fazer captura da camera do proprio computador, ou transmissão(RTP ou RTSP)
int main(int argc, const char * argv[]) {
    // insert code here...
    Mat quadro;
    
    VideoCapture vid(0);
    if (!vid.isOpened()) {
        return -1;
    }
    
    while (vid.read(quadro)) {
        //Caso t=preferisse usar um while(true), basta descomentar a linha abaixo:
        //vid >> quadro;
        imshow("webcam", quadro);
        if (waitKey(1000/fps) >= 0) { //será a pelo menos 'n' fps
            break;
        }
    }
    
    
    return 1;
}
