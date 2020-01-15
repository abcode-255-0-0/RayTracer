#include <iostream>
#include <fstream>

#include "Vector.h"

int main()
{
	int nx = 200;
	int ny = 100;
	std::ofstream outputFile;

	outputFile.open("imageOutput.ppm");
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			Vec3 color(float(i) / float(nx), float(j) / float(ny), 0.2f);

			int ir = int(255.99 * color[0]);
			int ig = int(255.99 * color[1]);
			int ib = int(255.99 * color[2]);

			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}

	outputFile.close();

	return 0;
}