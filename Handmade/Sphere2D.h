/*

  All code has been written by Karsten Vermeulen and may be used freely by anyone. It is by no
  means perfect and there is certainly room for improvement in some parts. As a whole, the code
  has been created as part of an engine for the purposes of educating other fellow programmers,
  and anyone else wishing to learn C++ and OOP. Feel free to use, copy, break, update and do as
  you wish with this code - it is there for all!

  UPDATED : April 2016

  -----------------------------------------------------------------------------------------------

- This class encapsulates a 2D sphere that determines collisions that may occur with other spheres
  or boxes as well as line segments and planes in the game world. There is a scale variable that 
  reflects the scale value of the game object that contains this component. This is used in the 
  inner calculations to provide accurate results, so no matter how large the game object is, the 
  bounding sphere will follow along accordingly. Unlike the AABB classes' m_scale and m_dimension 
  variables, in the Sphere2D class they are scalar values instead of vectors. That's because the 
  sphere can only be scaled in one dimension so to speak, and will not be scaled in all axes, 
  turning it into an ellipse. Even though the bound represents a 2D object, all member variables 
  are floats because that provides more accuracy when calculating the bounds, and will provide 
  better collision precision even if it's just a minute amount.
  
- There are four IsColliding() functions, one for checking two spheres for collision, another for
  checking if a sphere and a AABB collide, a third one for checking intersections with a line
  segment, and a fourth one for checking for collisions with a plane. The first one uses its own 
  radius and the radius of another sphere within a formula to calculate for collision. The sphere-box
  collision routine makes use of the AABB's IsColliding() routine, so that code is not duplicated. 
  Likewise the sphere-line and sphere-plane collision functions makes use of the Line2D's IsColliding()
  and the Plane2D's IsColliding() routines resepctively.

- The Update() routine calculates the radius based on the dimension of the sphere and its scale
  value, which is then used to calculate for collision. These values are purely for collision
  detection and not used for rendering. The Draw() function uses the Debug Manager to draw a simple
  2D sphere, because the sphere will only ever be drawn for debug purposes anyway. The sphere will
  be rendered based on how the matrix is transformed in the calling game object code (from within
  its Draw() routine). This is why it's best that the Sphere2D component is rendered straight after
  the game object is rendered.

- There is a small snag and that has to do with the order of transformations in the game object's
  Draw() code. If the game object is translated and then scaled, the position value in the sphere's
  IsColliding() routine doesn't need to be scaled. If however the game object is scaled and then
  translated, the position value needs to have scale considered. This is because the position of
  the sphere will be in local space and on a different scaled axis to the rest of the game objects,
  so the positional measurements are different, causing inaccurate calculations. This means that
  when checking for collision inside either of the IsColliding() routines, the positional data will
  differ against the box or sphere object being checked against. By default this class assumes
  translating BEFORE scaling in the game object code. The dimension of the sphere however always
  needs to consider scaling.

- Another thing to consider in the game object code is that rotation may be applied to the game
  object and no matter how much it's rotated, the Sphere2D will always remain the same. That's
  because the centre position and radius are always the same no matter how much it's rotated.

*/

#ifndef SPHERE_2D_H
#define SPHERE_2D_H

#include "AABB2D.h"
#include "Bound.h"
#include "Line2D.h"
#include "Plane2D.h"

class Sphere2D : public Bound
{

public :

	Sphere2D();
	virtual ~Sphere2D()  {}

public :

	float GetRadius() const;

public :

	void SetScale(float scale);
	void SetDimension(float dimension);
		
public :

	bool IsColliding(const AABB2D& secondBox) const;
	bool IsColliding(const Line2D& secondLine) const;
	bool IsColliding(const Plane2D& secondPlane) const;
	bool IsColliding(const Sphere2D& secondSphere) const;

public :

	virtual void Update();
	virtual void Draw();

private :

	float m_scale;
	float m_radius;
	float m_dimension;
	
};

#endif