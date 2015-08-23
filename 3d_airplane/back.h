void drawCylinder(double height, double radiusBase, double radiusTop, int slices, int stacks);
void back(void)
{
	float ycoordinate=6.6;
	float base=1.5;
	//glColor3f(1,0,0);
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(1.5, ycoordinate, 0.0);
		ycoordinate=ycoordinate+0.192;
		glRotatef(-90.0, 1.0, 0.0, 0.0);
			// Red color
		float top=base-0.0375/3;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		base=top;
		glPopMatrix();
	}

	//base=1.43750;
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(1.5, ycoordinate, 0.0);
		ycoordinate=ycoordinate+0.192;
		glRotatef(-90.0, 1.0, 0.0, 0.0);
			// Red color	// Grey color
		float top=base-0.0375/1.5;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		base=top;
		glPopMatrix();
	}

	//base=1.312500;
	for(int i=0;i<5;i++)
	{
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(1.5, ycoordinate, 0.0);
		ycoordinate=ycoordinate+0.192;
		glRotatef(-90.0, 1.0, 0.0, 0.0);
			// Red color	// Grey color
		float top=base-0.0375/0.85;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		base=top;
		glPopMatrix();
	}

	//base=1.091912;
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(1.5, ycoordinate, 0.0);
		ycoordinate=ycoordinate+0.192;
		glRotatef(-90.0, 1.0, 0.0, 0.0);
			// Red color	// Grey color
		float top=base-0.0375/0.5667;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		base=top;
		glPopMatrix();
	}

	//base=0.761049;
	for(int i=0;i<3;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glTranslatef(1.5, ycoordinate, 0.0);
		ycoordinate=ycoordinate+0.192;
		glRotatef(-90.0, 1.0, 0.0, 0.0);
			// Red color	// Grey color
		float top=base-0.0375/0.3778;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		base=top;
		glPopMatrix();
	}

	//base=0.463272;
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(1.5, ycoordinate, 0.0);
	ycoordinate=ycoordinate+0.192;
	glRotatef(-90.0, 1.0, 0.0, 0.0);
		// Red color	// Grey color
	float top=base-0.2;
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.192, base, top, 40, 1);
	glPopMatrix();	
	
	base=0.263272;
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(1.5, ycoordinate, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
		// Red color	// Grey color
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.192, base, 0.0, 30, 1);
	glPopMatrix();	

}
