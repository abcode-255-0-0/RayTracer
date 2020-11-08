#include <iostream>
#include <fstream>

#include "Ray.h"
#include "Vector.h"


int main()
{
	int nx = 600;
	int ny = 300;
	std::ofstream outputFile;

	Vec3 bottomLeft(-2.0f, -1.0f, -1.0f);
	Vec3 horizontal(4.0f, 0.0f, 0.0f);
	Vec3 vertical(0.0f, 2.0f, 0.0f);
	Vec3 origin(0.0f, 0.0f, 0.0f);

	outputFile.open("imageOutput.ppm");
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			Ray myRay(origin, bottomLeft + u * horizontal + v * vertical);
			Vec3 color = getColor(myRay);
		

			int ir = int(255.99 * color[0]);
			int ig = int(255.99 * color[1]);
			int ib = int(255.99 * color[2]);

			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}

	outputFile.close();

	return 0;
}