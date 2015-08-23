void wired(GLfloat ver[][3])
{
	GLfloat dx=0.3,dy=0.3,dz=0.0,m,mz,x,y,z,x1,y1,z1,point[2][3];
	point[0][0]=ver[7][0];
	point[0][1]=ver[8][1];
	point[0][2]=ver[7][2];
	point[1][0]=ver[4][0];
	point[1][1]=ver[5][1];
	point[1][2]=ver[4][2];
	//vertical lines
	//first region-triangle
	m=(ver[2][1]-ver[3][1])/(ver[2][0]-ver[3][0]);
	mz=(ver[2][2]-ver[3][2])/(ver[2][0]-ver[3][0]);
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	x=ver[2][0];
	y=ver[2][1];
	z=ver[2][2];
	x1=ver[1][0];
	y1=ver[1][1];
	z1=ver[1][2];
	while(x1<(ver[3][0]-dx))
	{
		x+=dx;
		y+=dy;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[1]);
		glVertex3fv(ver[2]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//second region-square
	dx=dy=0.3;
	mz=(ver[1][2]-ver[3][2])/(ver[1][0]-ver[3][0]);
	x=ver[1][0];
	y=ver[1][1];
	z=ver[1][2];
	x1=ver[0][0];
	y1=ver[0][1];
	z1=ver[0][2];
	while(x<ver[3][0])
	{
		x+=dx;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[0]);
		glVertex3fv(ver[1]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//third region-triangle
	m=(ver[3][1]-ver[4][1])/(ver[3][0]-ver[4][0]);
	mz=(ver[3][2]-ver[4][2])/(ver[3][0]-ver[4][0]);
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	x=ver[3][0];
	y=ver[3][1];
	z=ver[3][2];
	x1=ver[8][0];
	y1=ver[8][1];
	z1=ver[8][2];
	while(x1<(ver[4][0]-dx))
	{
		x+=dx;
		y+=dy;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[8]);
		glVertex3fv(ver[3]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//fourth region -triangle
	m=(ver[7][1]-ver[6][1])/(ver[7][0]-ver[6][0]);
	mz=(ver[7][2]-ver[6][2])/(ver[7][0]-ver[6][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[6][0];
	y=ver[6][1];
	z=ver[6][2];
	x1=ver[5][0];
	y1=ver[5][1];
	z1=ver[5][2];
	while(x1>(ver[7][0]+dx))
	{
		x-=dx;
		y-=dy;
		x1-=dx;
		z-=dz;
		z1-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[5]);
		glVertex3fv(ver[6]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//fifth region-rectangle
	dx=dy=0.3;
	mz=(ver[4][2]-point[0][2])/(ver[4][0]-point[0][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	x=point[0][0];
	y=point[0][1];
	z=point[0][2];
	x1=ver[7][0];
	y1=ver[7][1];
	z1=ver[7][2];
	while(x<(ver[4][0]-dx))
	{
		x+=dx;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[7]);
		glVertex3fv(point[0]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//sixth region -triangle
	dx=dy=0.3;
	m=(ver[8][1]-ver[7][1])/(ver[8][0]-ver[7][0]);
	mz=(ver[8][2]-ver[7][2])/(ver[8][0]-ver[7][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[7][0];
	y=ver[7][1];
	z=ver[7][2];
	x1=point[0][0];
	y1=point[0][1];
	z1=point[0][2];
	while(x1>(ver[8][0]+dx))
	{
		x-=dx;
		y-=dy;
		x1-=dx;
		z-=dz;
		z1-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point[0]);
		glVertex3fv(ver[7]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//seventh region-triangle
	dx=dy=0.3;
	m=(ver[4][1]-ver[5][1])/(ver[4][0]-ver[5][0]);
	mz=(ver[4][2]-ver[5][2])/(ver[4][0]-ver[5][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[4][0];
	y=ver[4][1];
	z=ver[4][2];
	x1=point[1][0];
	y1=point[1][1];
	z1=point[1][2];
	while(x1<(ver[5][0]-dx))
	{
		x+=dx;
		y+=dy;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point[1]);
		glVertex3fv(ver[4]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//horizontal lines
	//first region-triangle
	dx=dy=0.3;
	m=(ver[2][1]-ver[3][1])/(ver[2][0]-ver[3][0]);
	mz=(ver[2][2]-ver[3][2])/(ver[2][0]-ver[3][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[3][0];
	y=ver[3][1];
	z=ver[3][2];
	x1=ver[1][0];
	y1=ver[1][1];
	z1=ver[1][2];
	do
	{
		x-=dx;
		y-=dy;
		y1-=dy;
		z-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[1]);
		glVertex3fv(ver[3]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}while(y1<(ver[2][1]+dy));
	//second region-square
	dx=dy=0.3;
	x=ver[8][0];
	y=ver[8][1];
	z=ver[8][2];
	x1=ver[0][0];
	y1=ver[0][1];
	z1=ver[0][2];
	while(y<(ver[3][1]-dy))
	{
		y+=dy;
		y1+=dy;

		glBegin(GL_POLYGON);
		glVertex3fv(ver[0]);
		glVertex3fv(ver[8]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//third region-triangle
	dx=dy=0.3;
	m=(ver[3][1]-ver[4][1])/(ver[3][0]-ver[4][0]);
	mz=(ver[3][2]-ver[4][2])/(ver[3][0]-ver[4][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[4][0];
	y=ver[4][1];
	z=ver[4][2];
	x1=ver[8][0];
	y1=ver[8][1];
	z1=ver[8][2];
	while(y1<(ver[3][1]+dy))
	{
		x-=dx;
		y-=dy;
		y1-=dy;
		z-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[8]);
		glVertex3fv(ver[4]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//fourth region -triangle
	dx=dy=0.5;
	m=(ver[7][1]-ver[6][1])/(ver[7][0]-ver[6][0]);
	mz=(ver[7][2]-ver[6][2])/(ver[7][0]-ver[6][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.5;
	else
	{
		dy=m*dx;
		dx=0.5;
	}
	x=ver[7][0];
	y=ver[7][1];
	z=ver[7][2];
	x1=ver[5][0];
	y1=ver[5][1];
	z1=ver[5][2];
	while(y1>(ver[6][1]-dy))
	{
		x+=dx;
		y+=dy;
		y1+=dy;
		z+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[5]);
		glVertex3fv(ver[7]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//fifth region-rectangle
	dx=dy=0.1;
	x=point[1][0];
	y=point[1][1];
	z=point[1][2];
	x1=ver[7][0];
	y1=ver[7][1];
	z1=ver[7][2];
	while(y<ver[4][1])
	{
		y+=dy;
		y1+=dy;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[7]);
		glVertex3fv(point[1]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//sixth region -triangle
	dx=dy=0.3;
	m=(ver[8][1]-ver[7][1])/(ver[8][0]-ver[7][0]);
	mz=(ver[8][2]-ver[7][2])/(ver[8][0]-ver[7][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[8][0];
	y=ver[8][1];
	z=ver[8][2];
	x1=point[0][0];
	y1=point[0][1];
	z1=point[0][2];
	while(y1>ver[7][1])
	{
		x+=dx;
		y+=dy;
		y1+=dy;
		z+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point[0]);
		glVertex3fv(ver[8]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//seventh region-triangle
	dx=dy=0.3;
	m=(ver[4][1]-ver[5][1])/(ver[4][0]-ver[5][0]);
	mz=(ver[4][2]-ver[5][2])/(ver[4][0]-ver[5][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.3;
	else
	{
		dy=m*dx;
		dx=0.3;
	}
	x=ver[5][0];
	y=ver[5][1];
	z=ver[5][2];
	x1=point[1][0];
	y1=point[1][1];
	z1=point[1][2];
	while(y1<(ver[4][1]+dy))
	{
		x-=dx;
		y-=dy;
		y1-=dy;
		z-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point[1]);
		glVertex3fv(ver[5]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
}
void wired_tail(GLfloat ver[][3])
{
	GLfloat x,y,z,x1,y1,z1,m,mz,point[3],dx=0.2,dy=0.2,dz=0.0;
	point[0]=ver[1][0];
	point[1]=ver[0][1];
	point[2]=ver[1][2];
	//horizontal line
	//first region-triangle
	m=(ver[1][1]-ver[0][1])/(ver[1][0]-ver[0][0]);
	mz=(ver[1][2]-ver[0][2])/(ver[1][0]-ver[0][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.2;
	else
	{
		dx=0.2;
		dy=m*dx;
	}
	x=ver[1][0];
	y=ver[1][1];
	z=ver[1][2];
	x1=point[0];
	y1=point[1];
	z1=point[2];
	while(x1>(ver[0][0]+dx))
	{
		x-=dx;
		y-=dy;
		x1-=dx;
		z-=dz;
		z1-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point);
		glVertex3fv(ver[1]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//second region - triangle
	dx=dy=0.2;
	m=(ver[1][1]-ver[2][1])/(ver[1][0]-ver[2][0]);
	mz=(ver[1][2]-ver[2][2])/(ver[1][0]-ver[2][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.2;
	else
	{
		dx=0.2;
		dy=m*dx;
	}
	x=ver[1][0];
	y=ver[1][1];
	z=ver[1][2];
	x1=point[0];
	y1=point[1];
	z1=point[2];
	while(x1<(ver[2][0]-dx))
	{
		x+=dx;
		y+=dy;
		x1+=dx;
		z+=dz;
		z1+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point);
		glVertex3fv(ver[1]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//third region -triangle
	dx=dy=0.2;
	m=(ver[0][1]-ver[3][1])/(ver[0][0]-ver[3][0]);
	mz=(ver[0][2]-ver[3][2])/(ver[0][0]-ver[3][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.2;
	else
	{
		dx=0.2;
		dy=m*dx;
	}
	x=ver[3][0];
	y=ver[3][1];
	z=ver[3][2];
	x1=ver[2][0];
	y1=ver[2][1];
	z1=ver[2][2];
	while(x1>(ver[0][0]+dx))
	{
		x-=dx;
		y-=dy;
		x1-=dx;
		z-=dz;
		z1-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[2]);
		glVertex3fv(ver[3]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//horizontal lines
	//first region
	dx=dy=0.1;
	m=(ver[1][1]-ver[0][1])/(ver[1][0]-ver[0][0]);
	mz=(ver[1][2]-ver[0][2])/(ver[1][0]-ver[0][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.1;
	else
	{
		dx=0.1;
		dy=m*dx;
	}
	x=ver[0][0];
	y=ver[0][1];
	z=ver[0][2];
	x1=point[0];
	y1=point[1];
	z1=point[2];
	while(y1<(ver[1][1]-dy))
	{
		x+=dx;
		y+=dy;
		y1+=dy;
		z+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point);
		glVertex3fv(ver[0]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//second region
	dx=dy=0.5;
	m=(ver[1][1]-ver[2][1])/(ver[1][0]-ver[2][0]);
	mz=(ver[1][2]-ver[2][2])/(ver[1][0]-ver[2][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.5;
	else
	{
		dx=0.5;
		dy=m*dx;
	}
	x=ver[2][0];
	y=ver[2][1];
	z=ver[2][2];
	x1=point[0];
	y1=point[1];
	z1=point[2];
	while(y1<(ver[1][1]+dy))
	{
		x-=dx;
		y-=dy;
		y1-=dy;
		z-=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(point);
		glVertex3fv(ver[2]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}
	//third region
	dx=dy=0.5;
	m=(ver[0][1]-ver[3][1])/(ver[0][0]-ver[3][0]);
	mz=(ver[0][2]-ver[3][2])/(ver[0][0]-ver[3][0]);
	if(mz==0)
		dz=0.0;
	else
		dz=mz*dx;
	if(m==1)
		dx=dy=0.5;
	else
	{
		dx=0.5;
		dy=m*dx;
	}
	x=ver[0][0];
	y=ver[0][1];
	z=ver[0][2];
	x1=ver[2][0];
	y1=ver[2][1];
	z1=ver[2][2];
	while(y1>(ver[3][1]-dy))
	{
		x+=dx;
		y+=dy;
		y1+=dy;
		z+=dz;
		glBegin(GL_POLYGON);
		glVertex3fv(ver[2]);
		glVertex3fv(ver[0]);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
		glEnd();
	}

}
void join_wings(GLfloat ver[][3],GLfloat ver1[][3])
{	
	glBegin(GL_POLYGON);
	glVertex3fv(ver[0]);
	glVertex3fv(ver1[0]);
	glVertex3fv(ver1[2]);
	glVertex3fv(ver[2]);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(ver[0]);
	glVertex3fv(ver[8]);
	glVertex3fv(ver[7]);
	glVertex3fv(ver[6]);
	glVertex3fv(ver1[6]);
	glVertex3fv(ver1[7]);
	glVertex3fv(ver1[8]);
	glVertex3fv(ver1[0]);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(ver[2]);
	glVertex3fv(ver[3]);
	glVertex3fv(ver[4]);
	glVertex3fv(ver[5]);
	glVertex3fv(ver1[5]);
	glVertex3fv(ver1[4]);
	glVertex3fv(ver1[3]);
	glVertex3fv(ver1[2]);
	glEnd();
}
void join_tails(GLfloat v[][3],GLfloat v1[][3])
{
	glBegin(GL_POLYGON);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v1[1]);
	glVertex3fv(v1[0]);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(v[0]);
	glVertex3fv(v[3]);
	glVertex3fv(v1[3]);
	glVertex3fv(v1[0]);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v1[2]);
	glVertex3fv(v1[1]);
	glEnd();
}