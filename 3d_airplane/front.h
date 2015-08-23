void drawCylinder(double height, double radiusBase, double radiusTop, int slices, int stacks);
void front(void)
{
	float ycoordinate=-3.2;
	float top=1.5;
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		ycoordinate=ycoordinate-0.192;
		glTranslatef(1.5, ycoordinate, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(1,1,1);	// White color
		float base=top-0.0375/3;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		top=base;
		glPopMatrix();
	}

	ycoordinate=-4.16;
	top=1.43750;
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		ycoordinate=ycoordinate-0.192;
		glTranslatef(1.5, ycoordinate, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(1,1,1);	// White color
		float base=top-0.0375/1.5;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		top=base;
		glPopMatrix();
	}

	ycoordinate=-5.12;
	top=1.312500;
	for(int i=0;i<5;i++)
	{
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		ycoordinate=ycoordinate-0.192;
		glTranslatef(1.5, ycoordinate, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(1,1,1);	// White color
		float base=top-0.0375/0.85;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		top=base;
		glPopMatrix();
	}

	ycoordinate=-6.08;
	top=1.091912;
	for(int i=0;i<5;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		ycoordinate=ycoordinate-0.192;
		glTranslatef(1.5, ycoordinate, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(1,1,1);	// White color
		float base=top-0.0375/0.5667;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		top=base;
		glPopMatrix();
	}

	ycoordinate=-7.04;
	top=0.761049;
	for(int i=0;i<3;i++)
	{	
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		ycoordinate=ycoordinate-0.192;
		glTranslatef(1.5, ycoordinate, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(1,1,1);	// White color
		float base=top-0.0375/0.3778;
		// Parameters: height, base radius, top radius, slices, stacks
		drawCylinder(0.192, base, top, 30, 1);
		top=base;
		glPopMatrix();
	}

	ycoordinate=-7.616;
	top=0.463272;
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	ycoordinate=ycoordinate-0.192;
	glTranslatef(1.5, ycoordinate, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1,1,1);	// White color
	float base=top-0.2;
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.192, base, top, 30, 1);
	glPopMatrix();	
	
	ycoordinate=-7.808;
	top=0.263272;
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	ycoordinate=ycoordinate-0.192;
	glTranslatef(1.5, ycoordinate, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1,1,1);	// White color
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.192, 0.0, top, 30, 1);
	glPopMatrix();	
}
