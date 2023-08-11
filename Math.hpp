#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))

//maybe make a whole class for this?
struct matrix4x4 
{
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};

//maybe make a whole class for this?
struct matrix3x4
{
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
};

class Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float _x, float _y);
	Vector3(float _x, float _y, float _z);

	/// <summary>Adds two vectors.
	/// Adds corresponding components together.</summary>
	Vector3 operator +(Vector3 b);

	/// <summary>Adds two vectors.
	/// Adds corresponding components together.</summary>
	Vector3 operator +=(Vector3 b);

	/// <summary>Subtracts one vector from another.
	/// Subtracts each component of b from a.</summary>
	Vector3 operator -(Vector3 b);

	/// <summary>Subtracts one vector from another.
	/// Subtracts each component of b from a.</summary>
	Vector3 operator -=(Vector3 b);

	/// <summary>Multiplies a vector by a number.
	/// Multiplies each component of a by a number d.</summary>
	Vector3 operator *(float d);

	/// <summary>Divides a vector by a number.
	// Divides each component of a by a number d.</summary>
	Vector3 operator /(float d);

	///	<returns>Returns true if two vectors are approximately equal.
	/// To allow for floating point inaccuracies, the two vectors are considered equal if the magnitude of their difference is less than 1e-5.</returns>
	bool operator ==(Vector3 rhs);

	///	<returns>Returns true if vectors are different.
	/// Very close vectors are treated as being equal.</returns>
	bool operator !=(Vector3 rhs);

	/// <summary>Shorthand for writing Vector3(0.f, 0.f, 0.f)</summary>
	///	<returns>Vector3(0.f, 0.f, 0.f)</returns>
	static Vector3 Zero();

	/// <summary>Shorthand for writing Vector3(1.f, 1.f, 1.f)</summary>
	///	<returns>Vector3(1.f, 1.f, 1.f)</returns>
	static Vector3 One();

	/// <summary>Shorthand for writing Vector3(0.f, 1.f, 0.f)</summary>
	///	<returns>Vector3(0.f, 1.f, 0.f)</returns>
	static Vector3 Up();

	/// <summary>Shorthand for writing Vector3(0.f, -1.f, 0.f)</summary>
	///	<returns>Vector3(0.f, -1.f, 0.f)</returns>
	static Vector3 Down();

	/// <summary>Shorthand for writing Vector3(-1.f, 0.f, 0.f)</summary>
	///	<returns>Vector3(-1.f, 0.f, 0.f)</returns>
	static Vector3 Left();

	/// <summary>Shorthand for writing Vector3(1.f, 0.f, 0.f)</summary>
	///	<returns>Vector3(1.f, 0.f, 0.f)</returns>
	static Vector3 Right();

	/// <summary>Shorthand for writing Vector3(0.f, 0.f, 1.f)</summary>
	///	<returns>Vector3(0.f, 0.f, 1.f)</returns>
	static Vector3 Forward();

	/// <summary>Shorthand for writing Vector3(0.f, 0.f, -1.f)</summary>
	///	<returns>Vector3(0.f, 0.f, -1.f)</returns>
	static Vector3 Back();

	/// <summary>Shorthand for writing Vector3(FLT_MAX, FLT_MAX, FLT_MAX)</summary>
	///	<returns>Vector3(FLT_MAX, FLT_MAX, FLT_MAX)</returns>
	static Vector3 PositiveInfinity();

	/// <summary>Shorthand for writing Vector3(FLT_MIN, FLT_MIN, FLT_MIN)</summary>
	///	<returns>Vector3(FLT_MIN, FLT_MIN, FLT_MIN)</returns>
	static Vector3 NegativeInfinity();

	/// <summary>Set x, y and z components of an existing Vector3.</summary>
	void Set(float newX, float newY, float newZ);

	/// <summary>Multiplies two vectors component-wise.
	/// Every component in the result is a component of a multiplied by the same component of b.</summary>
	///	<returns>Returns the scaled vector</returns>
	static Vector3 Scale(Vector3 a, Vector3 b);

	/// <summary>Multiplies two vectors component-wise.
	/// Every component in the result is a component of a multiplied by the same component of b.</summary>
	///	<returns>Returns the scaled vector</returns>
	void Scale(Vector3 scale);
	
	/// <summary>The cross product of two vectors results in a third vector which is perpendicular to the two input vectors.
	/// The result's magnitude is equal to the magnitudes of the two inputs multiplied together and then multiplied by the sine of the angle between the inputs. 
	/// You can determine the direction of the result vector using the "left hand rule".</summary>
	///	<returns>Returns the cross product of two vectors.</returns>
	static Vector3 Cross(Vector3 lhs, Vector3 rhs);

	/// <summary>The cross product of two vectors results in a third vector which is perpendicular to the two input vectors.
	/// The result's magnitude is equal to the magnitudes of the two inputs multiplied together and then multiplied by the sine of the angle between the inputs. 
	/// You can determine the direction of the result vector using the "left hand rule".</summary>
	///	<returns>Returns the cross product of two vectors.</returns>
	Vector3 Cross(Vector3 rhs);
	
	/// <summary>The dot product is a float value equal to the magnitudes of the two vectors multiplied together and then multiplied by the cosine of the angle between them.
	/// For normalized vectors Dot returns 1 if they point in exactly the same direction, -1 if they point in completely opposite directionsand zero if the vectors are perpendicular.</summary>
	///	<returns>Returns the dot Product of two vectors.</returns>
	static float Dot(Vector3 lhs, Vector3 rhs);

	/// <summary>The dot product is a float value equal to the magnitudes of the two vectors multiplied together and then multiplied by the cosine of the angle between them.
	/// For normalized vectors Dot returns 1 if they point in exactly the same direction, -1 if they point in completely opposite directionsand zero if the vectors are perpendicular.</summary>
	///	<returns>Returns the dot Product of two vectors.</returns>
	float Dot(Vector3 rhs);
	
	/// <summary>Makes this vector have a magnitude of 1.
	/// <para>When normalized, a vector keeps the same direction but its length is 1.0.
	/// Note that this function will change the current vector.
	/// If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	static Vector3 Normalize(Vector3 value);

	/// <summary>Makes this vector have a magnitude of 1.
	/// <para>When normalized, a vector keeps the same direction but its length is 1.0.
	/// Note that this function will change the current vector.
	/// If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	void Normalize();

	/// <summary>When normalized, a vector keeps the same direction but its length is 1.0.
	/// Note that the current vector is unchangedand a new normalized vector is returned.
	/// If you want to normalize the current vector, use Normalize function.
	/// If the vector is too small to be normalized a zero vector will be returned.</summary>
	///	<returns>Returns this vector with a magnitude of 1</returns>
	Vector3 Normalized();
	
	/// <summary>Vector3.Distance(a,b) is the same as (a-b).magnitude.</summary>
	///	<returns>Returns the distance between a and b.</returns>
	static float Distance(Vector3 a, Vector3 b);

	/// <summary>Vector3.Distance(a,b) is the same as (a-b).magnitude.</summary>
	///	<returns>Returns the distance between this and b.</returns>
	float Distance(Vector3 b);
	
	///	<returns>Returns a copy of vector with its magnitude clamped to maxLength.</returns>
	static Vector3 ClampMagnitude(Vector3 vector, float maxLength);

	/// <summary>The length of the vector is square root of (x*x+y*y+z*z).
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	/// <returns>Returns the length of this vector.</returns>
	static float Magnitude(Vector3 vector);

	/// <summary>The length of the vector is square root of (x*x+y*y+z*z).
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	/// <returns>Returns the length of this vector.</returns>
	float Magnitude();
	
	/// <summary>The magnitude of a vector v is calculated as Mathf.Sqrt(Vector3.Dot(v, v)). However, the Sqrt calculation is quite complicated and takes longer to execute than the normal arithmetic operations.
	///  Calculating the squared magnitude instead of using the magnitude property is much faster - the calculation is basically the same only without the slow Sqrt call.
	///  If you are using magnitudes simply to compare distances, then you can just as well compare squared magnitudes against the squares of distances since the comparison will give the same result.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	static float SqrMagnitude(Vector3 vector);

	/// <summary>The magnitude of a vector v is calculated as Mathf.Sqrt(Vector3.Dot(v, v)). However, the Sqrt calculation is quite complicated and takes longer to execute than the normal arithmetic operations.
	///  Calculating the squared magnitude instead of using the magnitude property is much faster - the calculation is basically the same only without the slow Sqrt call.
	///  If you are using magnitudes simply to compare distances, then you can just as well compare squared magnitudes against the squares of distances since the comparison will give the same result.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	float SqrMagnitude();

	///	<returns>Returns a vector that is made from the smallest components of two vectors.</returns>
	static Vector3 Min(Vector3 lhs, Vector3 rhs);

	///	<returns>Returns a vector that is made from the largest components of two vectors.</returns>
	static Vector3 Max(Vector3 lhs, Vector3 rhs);

	/// <summary>ToString Converts An Object To Its String Representation So That It Is Suitable For Display</summary>
	///	<returns>Returns A String Formated X, Y, Z.</returns>
	std::string ToString();

	/// <summary>DebugPrint Converts An Object To Its String Representation Then Prints It For Debugging Purposes</summary>
	void DebugPrint();

	/// <summary>Reflects a vector off the plane defined by a normal.
	/// The inNormal vector defines a plane(a plane's normal is the vector that is perpendicular to its surface).
	/// the inDirection vector is treated as a directional arrow coming in to the plane.
	/// The returned value is a vector of equal magnitude to inDirection but with its direction reflected.</summary>
	///	<returns>Returns the reflected point</returns>
	static Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);

	/// <summary>Calculates the angle between vectors from and to.
	/// The angle returned is the angle of rotation from the first vector to the second, when treating these two vector inputs as directions.
	/// Note: The angle returned will always be between 0 and 180 degrees, because the method returns the smallest angle between the vectors.
	/// That is, it will never return a reflex angle</summary>
	///	<returns>Returns the angle in degrees between the two vectors.</returns>
	static float Angle(Vector3 from, Vector3 to);

	/// <summary>Calculates the angle between vectors from and to.
	/// The angle returned is the angle of rotation from the first vector to the second, when treating these two vector inputs as directions.
	/// Note: The angle returned will always be between 0 and 180 degrees, because the method returns the smallest angle between the vectors.
	/// That is, it will never return a reflex angle</summary>
	///	<returns>Returns the angle in degrees between the two vectors.</returns>
	static float AngleBetween(Vector3 from, Vector3 to);

	/// <summary>Calculates the signed angle between vectors from and to in relation to axis. 
	/// The angle returned is the angle of rotation from the first vector to the second, when treating these first two vector inputs as directions.
	/// These two vectors also define the plane of rotation, meaning they are parallel to the plane.
	/// This means the axis of rotation around which the angle is calculated is the cross product of the firstand second vectors(and not the 3rd "axis" parameter).
	/// You can use the "left hand rule" to determine the axis of rotation, given the two input vectors.
	/// The third input(named the “axis” parameter), gives you a way to provide a contextual direction to include in the calculation.
	/// This has the result of flipping the sign of the result depending on whether this third vector that you supply falls above or below the plane of rotation defined by the first two input vectors.
	/// Therefore the sign of the final result depends on two things : the order in which you supply the "from" and "to" vector, and the direction of the third "axis" vector.
	///  Note : The angle returned will always be between - 180 and 180 degrees, because the method returns the smallest angle between the vectors.
	/// That is, it will never return a reflex angle.</summary>
	///	<returns>Returns the signed angle between from and to in degrees.</returns>
	static float SignedAngle(Vector3 from, Vector3 to, Vector3 axis);

	/// <summary>CalculateAngle Calculates the angle between two points</summary>
	///	<returns>Returns vector3 with the x and y componets filled in z will always be 0</returns>
	static Vector3 CalculateAngle(Vector3 src, Vector3 dst);

	/// <summary>To understand vector projection, imagine that onNormal is resting on a line pointing in its direction. Somewhere along that line will be the nearest point to the tip of vector. The projection is just onNormal rescaled so that it reaches that point on the line.</summary>
	///	<returns>Returns a vector projected onto another vector</returns>
	static Vector3 Project(Vector3 vector, Vector3 onNormal);

	/// <summary>Projects a vector onto a plane defined by a normal orthogonal to the plane. 
	/// A Vector3 stores the position of the given vector in 3d space.
	/// A second Vector3 is given by planeNormal and defines a direction from a plane towards vector that passes through the origin.
	/// Vector3.ProjectOnPlane uses the two Vector3 values to generate the position of vector in the planeNormal direction, and return the location of the Vector3 on the plane.</summary>
	///	<returns>Returns the location of the vector on the plane.</returns>
	static Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal);

	/// <summary>Projects a vector onto a plane defined by a normal orthogonal to the plane. 
	/// A Vector3 stores the position of the given vector in 3d space.
	/// A second Vector3 is given by planeNormal and defines a direction from a plane towards vector that passes through the origin.
	/// Vector3.Exclude uses the two Vector3 values to generate the position of vector in the planeNormal direction, and return the location of the Vector3 on the plane.</summary>
	///	<returns>Returns the location of the vector on the plane.</returns>
	static Vector3 Exclude(Vector3 excludeThis, Vector3 fromThat);

	/// <summary>Linearly interpolates between two points. 
	/// Interpolates between the points and b by the interpolant t.
	/// The parameter t is clamped to the range[0, 1].
	/// This is most commonly used to find a point some fraction of the way along a line between two endpoints(e.g.to move an object gradually between those points).</summary>
	///	<returns>Returns Interpolated value, equals to a + (b - a) * t.</returns>
	static Vector3 Lerp(Vector3 a, Vector3 b, float t);

	/// <summary>Linearly interpolates between two vectors. 
	/// Interpolates between the vectors aand b by the interpolant t.
	/// This is most commonly used to find a point some fraction of the way along a line between two endpoints(e.g.to move an object gradually between those points).</summary>
	///	<returns>Returns When t = 0 returns a. When t = 1 returns b. When t = 0.5 returns the point midway between a and b.</returns>
	static Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t);

	/// <summary>Calculate a position between the points specified by current and target, moving no farther than the distance specified by maxDistanceDelta. 
	/// Use the MoveTowards member to move an object at the current position toward the target position.
	/// By updating an object’s position each frame using the position calculated by this function, you can move it towards the target smoothly.
	/// Control the speed of movement with the maxDistanceDelta parameter.
	/// If the current position is already closer to the target than maxDistanceDelta, the value returned is equal to target; the new position does not overshoot target.
	/// To make sure that object speed is independent of frame rate, multiply the maxDistanceDelta value by Time.deltaTime(or Time.fixedDeltaTime in a FixedUpdate loop).</summary>
	///	<returns>Returns the new position</returns>
	static Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.
	/// The most common use is for smoothing a follow camera.</summary>
	///	<returns>Returns a point slightly closer to the finish</returns>
	static Vector3 SmoothDamp(Vector3 current, Vector3 target, Vector3& currentVelocity, float smoothTime, float maxSpeed);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.
	/// The most common use is for smoothing a follow camera.</summary>
	///	<returns>Returns a point slightly closer to the finish</returns>
	static Vector3 SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.
	/// The most common use is for smoothing a follow camera.</summary>
	///	<returns>Returns a point slightly closer to the finish</returns>
	static Vector3 SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime, float maxSpeed = FLT_MAX, float deltaTime = 0.03125f);
};

Vector3::Vector3()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}

Vector3::Vector3(float _x, float _y)
{
	x = _x;
	y = _y;
	z = 0.f;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3 Vector3::operator +(Vector3 b)
{
	return Vector3(x + b.x, y + b.y, z + b.z);
}

Vector3 Vector3::operator +=(Vector3 b)
{
	return Vector3(x + b.x, y + b.y, z + b.z);
}

Vector3 Vector3::operator -(Vector3 b)
{
	return Vector3(x - b.x, y - b.y, z - b.z);
}

Vector3 Vector3::operator -=(Vector3 b)
{
	return Vector3(x - b.x, y - b.y, z - b.z);
}

Vector3 Vector3::operator *(float d)
{
	return Vector3(x * d, y * d, z * d);
}

Vector3 Vector3::operator /(float d)
{
	return Vector3(x / d, y / d, z / d);
}

bool Vector3::operator ==(Vector3 rhs)
{
	float num = x - rhs.x;
	float num2 = y - rhs.y;
	float num3 = z - rhs.z;
	float num4 = num * num + num2 * num2 + num3 * num3;
	return num4 < 9.9999994E-11f;
}

bool Vector3::operator !=(Vector3 rhs)
{
	return !(Vector3(x, y, z) == rhs);
}

Vector3 Vector3::Zero()
{
	return Vector3(0.f, 0.f, 0.f);
}

Vector3 Vector3::One()
{
	return Vector3(1.f, 1.f, 1.f);
}

Vector3 Vector3::Up()
{
	return Vector3(0.f, 1.f, 0.f);
}

Vector3 Vector3::Down()
{
	return Vector3(0.f, -1.f, 0.f);
}

Vector3 Vector3::Left()
{
	return  Vector3(-1.f, 0.f, 0.f);
}

Vector3 Vector3::Right()
{
	return Vector3(1.f, 0.f, 0.f);
}

Vector3 Vector3::Forward()
{
	return Vector3(0.f, 0.f, 1.f);
}

Vector3 Vector3::Back()
{
	return Vector3(0.f, 0.f, -1.f);
}

Vector3 Vector3::PositiveInfinity()
{
	return Vector3(FLT_MAX, FLT_MAX, FLT_MAX);
}

Vector3 Vector3::NegativeInfinity()
{
	return Vector3(FLT_MIN, FLT_MIN, FLT_MIN);
}

void Vector3::Set(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

Vector3 Vector3::Scale(Vector3 a, Vector3 b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

void Vector3::Scale(Vector3 scale)
{
	x *= scale.x;
	y *= scale.y;
	z *= scale.z;
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
	return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

Vector3 Vector3::Cross(Vector3 rhs)
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

float Vector3::Dot(Vector3 lhs, Vector3 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float Vector3::Dot(Vector3 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::Normalize(Vector3 value)
{
	float num = Magnitude(value);
	bool flag = num > 1E-05f;
	Vector3 result;
	if (flag)
	{
		result = value / num;
	}
	else
	{
		result = Vector3::Zero();
	}
	return result;
}

void Vector3::Normalize()
{
	float num = Magnitude(Vector3(x, y, z));
	bool flag = num > 1E-05f;
	if (flag)
	{
		x /= num;
		y /= num;
		z /= num;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
	}
}

Vector3 Vector3::Normalized()
{
	return Normalize(Vector3(x, y, z));
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
	float num = a.x - b.x;
	float num2 = a.y - b.y;
	float num3 = a.z - b.z;
	return (float)std::sqrt((double)(num * num + num2 * num2 + num3 * num3));
}

float Vector3::Distance(Vector3 b)
{
	float num = x - b.x;
	float num2 = y - b.y;
	float num3 = z - b.z;
	return (float)std::sqrt((double)(num * num + num2 * num2 + num3 * num3));
}

Vector3 Vector3::ClampMagnitude(Vector3 vector, float maxLength)
{
	float sqrMagnitude = vector.SqrMagnitude();
	bool flag = sqrMagnitude > maxLength * maxLength;
	Vector3 result;
	if (flag)
	{
		float num = (float)std::sqrt((double)sqrMagnitude);
		float num2 = vector.x / num;
		float num3 = vector.y / num;
		float num4 = vector.z / num;
		result = Vector3(num2 * maxLength, num3 * maxLength, num4 * maxLength);
	}
	else
	{
		result = vector;
	}
	return result;
}

float Vector3::Magnitude(Vector3 vector)
{
	return (float)std::sqrt((double)(std::powf(vector.x, 2) + std::powf(vector.y, 2) + std::powf(vector.z, 2)));
}

float Vector3::Magnitude()
{
	return (float)std::sqrt((double)(std::powf(x, 2) + std::powf(y, 2) + std::powf(z, 2)));
}

float Vector3::SqrMagnitude(Vector3 vector)
{
	return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float Vector3::SqrMagnitude()
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Min(Vector3 lhs, Vector3 rhs)
{
	return Vector3(min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z));
}

Vector3 Vector3::Max(Vector3 lhs, Vector3 rhs)
{
	return Vector3(max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z));
}

std::string Vector3::ToString()
{
	char buffer[64];

	sprintf(buffer, "X:%f, Y:%f  Z:%f", x, y, z);

	return buffer;
}

void Vector3::DebugPrint()
{
	printf("X:%f, Y:%f  Z:%f\n", x, y, z);
}

Vector3 Vector3::Reflect(Vector3 inDirection, Vector3 inNormal)
{
	float num = -2.f * Dot(inNormal, inDirection);
	return Vector3(num * inNormal.x + inDirection.x, num * inNormal.y + inDirection.y, num * inNormal.z + inDirection.z);
}

float Vector3::Angle(Vector3 from, Vector3 to)
{
	float num = (float)std::sqrt((double)(from.SqrMagnitude() * to.SqrMagnitude()));
	bool flag = num < 1E-15f;
	float result;
	if (flag)
	{
		result = 0.f;
	}
	else
	{
		float dot = Dot(from, to) / num;

		bool flag = dot < -1.f;
		if (flag)
		{
			dot = -1.f;
		}
		else
		{
			bool flag2 = dot > 1.f;
			if (flag2)
			{
				dot = 1.f;
			}
		}

		float num2 = dot;
		result = (float)std::acos((double)num2) * 57.29578f;
	}
	return result;
}

float Vector3::AngleBetween(Vector3 from, Vector3 to)
{
	float dot = Dot(from.Normalized(), to.Normalized());

	bool flag = dot < -1.f;
	if (flag)
	{
		dot = -1.f;
	}
	else
	{
		bool flag2 = dot > 1.f;
		if (flag2)
		{
			dot = 1.f;
		}
	}

	return (float)std::acos((double)dot);
}

float Vector3::SignedAngle(Vector3 from, Vector3 to, Vector3 axis)
{
	float num = Angle(from, to);
	float num2 = from.y * to.z - from.z * to.y;
	float num3 = from.z * to.x - from.x * to.z;
	float num4 = from.x * to.y - from.y * to.x;
	float num5 = ((axis.x * num2 + axis.y * num3 + axis.z * num4) >= 0.f) ? 1.f : -1.f;
	return num * num5;
}

Vector3 Vector3::CalculateAngle(Vector3 src, Vector3 dst)
{
	Vector3 direction = Vector3(src.x - dst.x, src.y - dst.y, src.z - dst.z);
	return Vector3(RAD2DEG(asin(direction.y / direction.Magnitude())), RAD2DEG(-atan2(direction.x, -direction.z)), 0.f);
}

Vector3 Vector3::Project(Vector3 vector, Vector3 onNormal)
{
	float num = Dot(onNormal, onNormal);
	bool flag = num < FLT_EPSILON;
	Vector3 result;
	if (flag)
	{
		result = Vector3::Zero();
	}
	else
	{
		float num2 = Dot(vector, onNormal);
		result = Vector3(onNormal.x * num2 / num, onNormal.y * num2 / num, onNormal.z * num2 / num);
	}
	return result;
}

Vector3 Vector3::ProjectOnPlane(Vector3 vector, Vector3 planeNormal)
{
	float num = Dot(planeNormal, planeNormal);
	bool flag = num < FLT_EPSILON;
	Vector3 result;
	if (flag)
	{
		result = vector;
	}
	else
	{
		float num2 = Dot(vector, planeNormal);
		result = Vector3(vector.x - planeNormal.x * num2 / num, vector.y - planeNormal.y * num2 / num, vector.z - planeNormal.z * num2 / num);
	}
	return result;
}

Vector3 Vector3::Exclude(Vector3 excludeThis, Vector3 fromThat)
{
	return ProjectOnPlane(fromThat, excludeThis);
}

Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	bool flag = t < 0.f;
	float result;
	if (flag)
	{
		result = 0.f;
	}
	else
	{
		bool flag2 = t > 1.f;
		if (flag2)
		{
			result = 1.f;
		}
		else
		{
			result = t;
		}
	}

	t = result;
	return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
}

Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t)
{
	return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
}

Vector3 Vector3::MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta)
{
	float num = target.x - current.x;
	float num2 = target.y - current.y;
	float num3 = target.z - current.z;
	float num4 = num * num + num2 * num2 + num3 * num3;
	bool flag = num4 == 0.f || (maxDistanceDelta >= 0.f && num4 <= maxDistanceDelta * maxDistanceDelta);
	Vector3 result;
	if (flag)
	{
		result = target;
	}
	else
	{
		float num5 = (float)std::sqrt((double)num4);
		result = Vector3(current.x + num / num5 * maxDistanceDelta, current.y + num2 / num5 * maxDistanceDelta, current.z + num3 / num5 * maxDistanceDelta);
	}
	return result;
}

Vector3 Vector3::SmoothDamp(Vector3 current, Vector3 target, Vector3& currentVelocity, float smoothTime, float maxSpeed)
{
	float deltaTime = 0.03125f;//Time.deltaTime;
	return SmoothDamp(current, target, currentVelocity, smoothTime, maxSpeed, deltaTime);
}

Vector3 Vector3::SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime)
{
	float deltaTime = 0.03125f;//Time.deltaTime;
	float positiveInfinity = FLT_MAX;
	return SmoothDamp(current, target, currentVelocity, smoothTime, positiveInfinity, deltaTime);
}

Vector3 Vector3::SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime, float maxSpeed, float deltaTime)
{
	smoothTime = max(0.0001f, smoothTime);
	float num = 2.f / smoothTime;
	float num2 = num * deltaTime;
	float num3 = 1.f / (1.f + num2 + 0.48f * num2 * num2 + 0.235f * num2 * num2 * num2);
	float num4 = current.x - target.x;
	float num5 = current.y - target.y;
	float num6 = current.z - target.z;
	Vector3 vector = target;
	float num7 = maxSpeed * smoothTime;
	float num8 = num7 * num7;
	float num9 = num4 * num4 + num5 * num5 + num6 * num6;
	bool flag = num9 > num8;
	if (flag)
	{
		float num10 = (float)std::sqrt((double)num9);
		num4 = num4 / num10 * num7;
		num5 = num5 / num10 * num7;
		num6 = num6 / num10 * num7;
	}
	target.x = current.x - num4;
	target.y = current.y - num5;
	target.z = current.z - num6;
	float num11 = (currentVelocity.x + num * num4) * deltaTime;
	float num12 = (currentVelocity.y + num * num5) * deltaTime;
	float num13 = (currentVelocity.z + num * num6) * deltaTime;
	currentVelocity.x = (currentVelocity.x - num * num11) * num3;
	currentVelocity.y = (currentVelocity.y - num * num12) * num3;
	currentVelocity.z = (currentVelocity.z - num * num13) * num3;
	float num14 = target.x + (num4 + num11) * num3;
	float num15 = target.y + (num5 + num12) * num3;
	float num16 = target.z + (num6 + num13) * num3;
	float num17 = vector.x - current.x;
	float num18 = vector.y - current.y;
	float num19 = vector.z - current.z;
	float num20 = num14 - vector.x;
	float num21 = num15 - vector.y;
	float num22 = num16 - vector.z;
	bool flag2 = num17 * num20 + num18 * num21 + num19 * num22 > 0.f;
	if (flag2)
	{
		num14 = vector.x;
		num15 = vector.y;
		num16 = vector.z;
		currentVelocity.x = (num14 - vector.x) / deltaTime;
		currentVelocity.y = (num15 - vector.y) / deltaTime;
		currentVelocity.z = (num16 - vector.z) / deltaTime;
	}
	return Vector3(num14, num15, num16);
}

class Vector2
{
public:
	float x, y;

	/// <summary>Representation of 2D vectors and points. 
	/// This structure is used in some places to represent 2D positions and vectors(e.g.texture coordinates in a Mesh or texture offsets in Material).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector2();

	/// <summary>Representation of 2D vectors and points. 
	/// This structure is used in some places to represent 2D positions and vectors(e.g.texture coordinates in a Mesh or texture offsets in Material).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector2(float _x, float _y);

	/// <summary>Adds two vectors. 
	/// Adds corresponding components together.</summary>
	Vector2 operator +(Vector2 b);

	/// <summary>Negates a vector.
	/// Each component in the result is negated.</summary>
	Vector2 operator -(Vector2 b);

	/// <summary>Multiplies a vector by another vector. 
	/// Multiplies each component of a by its matching component from b.</summary>
	Vector2 operator *(Vector2 b);

	/// <summary>Divides a vector by another vector. 
	/// Divides each component of a by its matching component from b.</summary>
	Vector2 operator /(Vector2 b);

	/// <summary>Multiplies a vector by a number. 
	/// Multiplies each component of a by a number d.</summary>
	Vector2 operator *(float d);

	/// <summary>Divides a vector by a number. 
	/// Divides each component of a by a number d.</summary>
	Vector2 operator /(float d);

	/// <summary>Returns true if two vectors are approximately equal. 
	/// To allow for floating point inaccuracies, the two vectors are considered equal if the magnitude of their difference is less than 1e-5.</summary>
	bool operator ==(Vector2 rhs);

	/// <summary>Returns true if two vectors are approximately not equal. 
	///To allow for floating point inaccuracies, the two vectors are considered not equal if the magnitude of their difference is less than 1e-5.</summary>
	bool operator !=(Vector2 rhs);

	/// <summary>Shorthand for writing Vector2(0, 0).</summary>
	///	<returns>Vector2(0, 0)</returns>
	static Vector2 Zero();

	/// <summary>Shorthand for writing Vector2(1, 1).</summary>
	///	<returns>Vector2(1, 1)</returns>
	static Vector2 One();

	/// <summary>Shorthand for writing Vector2(0, 1).</summary>
	///	<returns>Vector2(0, 1)</returns>
	static Vector2 Up();

	/// <summary>Shorthand for writing Vector2(0, -1).</summary>
	///	<returns>Vector2(0, -1)</returns>
	static Vector2 Down();

	/// <summary>Shorthand for writing Vector2(-1, 0).</summary>
	///	<returns>Vector2(-1, 0)</returns>
	static Vector2 Left();

	/// <summary>Shorthand for writing Vector2(1, 0).</summary>
	///	<returns>Vector2(1, 0)</returns>
	static Vector2 Right();

	/// <summary>Shorthand for writing Vector2(FLT_MAX, FLT_MAX).</summary>
	///	<returns>Vector2(FLT_MAX, FLT_MAX)</returns>
	static Vector2 PositiveInfinity();

	/// <summary>Shorthand for writing Vector2(FLT_MIN, FLT_MIN).</summary>
	///	<returns>Vector2(FLT_MIN, FLT_MIN)</returns>
	static Vector2 NegativeInfinity();

	/// <summary>Set x and y components of an existing Vector2.</summary>
	void Set(float newX, float newY);

	/// <summary>Multiplies two vectors component-wise. 
	/// Every component in the result is a component of a multiplied by the same component of b.</summary>
	///	<returns>The scaled vector</returns>
	static Vector2 Scale(Vector2 a, Vector2 b);

	/// <summary>Multiplies every component of this vector by the same component of scale.</summary>
	void Scale(Vector2 scale);

	/// <summary>For normalized vectors Dot returns 1 if they point in exactly the same direction; -1 if they point in completely opposite directions; and a number in between for other cases (e.g. Dot returns zero if vectors are perpendicular). 
	/// For vectors of arbitrary length the Dot return values are similar : they get larger when the angle between vectors decreases.</summary>
	///	<returns>The dot product of lhs and rhs</returns>
	static float Dot(Vector2 lhs, Vector2 rhs);

	/// <summary>For normalized vectors Dot returns 1 if they point in exactly the same direction; -1 if they point in completely opposite directions; and a number in between for other cases (e.g. Dot returns zero if vectors are perpendicular). 
	/// For vectors of arbitrary length the Dot return values are similar : they get larger when the angle between vectors decreases.</summary>
	///	<returns>The dot product of this and rhs</returns>
	float Dot(Vector2 rhs);

	/// <summary>Makes this vector have a magnitude of 1. 
	/// When normalized, a vector keeps the same direction but its length is 1.0.
	/// Note that this function will change the current vector.If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	///	<returns>The normalized vector with a magnitude of 1</returns>
	static Vector2 Normalize(Vector2 value);

	/// <summary>Makes this vector have a magnitude of 1. 
	/// When normalized, a vector keeps the same direction but its length is 1.0.
	/// Note that this function will change the current vector.If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	///	<returns>The normalized vector with a magnitude of 1</returns>
	void Normalize();

	/// <summary>When normalized, a vector keeps the same direction but its length is 1.0. 
	/// Note that the current vector is unchangedand a new normalized vector is returned.
	/// If you want to normalize the current vector, use Normalize function.
	/// If the vector is too small to be normalized a zero vector will be returned.</summary>
	///	<returns>Returns this vector with a magnitude of 1</returns>
	Vector2 Normalized();

	/// <summary>Vector2.Distance(a,b) is the same as (a-b).magnitude.</summary>
	///	<returns>Returns the distance between a and b.</returns>
	static float Distance(Vector2 a, Vector2 b);

	/// <summary>Vector2.Distance(a,b) is the same as (a-b).magnitude.</summary>
	///	<returns>Returns the distance between this and b.</returns>
	float Distance(Vector2 b);

	///	<returns>A copy of vector with its magnitude clamped to maxLength.</returns>
	static Vector2 ClampMagnitude(Vector2 vector, float maxLength);

	/// <summary>The length of the vector is square root of (x*x+y*y). 
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	///	<returns>Returns the length of this vector</returns>
	float Magnitude();

	/// <summary>The length of the vector is square root of (x*x+y*y). 
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	///	<returns>Returns the length of this vector</returns>
	static float Magnitude(Vector2 a);

	/// <summary>Calculating the squared magnitude instead of the magnitude is much faster.
	/// Often if you are comparing magnitudes of two vectors you can just compare their squared magnitudes.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	static float SqrMagnitude(Vector2 a);

	/// <summary>Calculating the squared magnitude instead of the magnitude is much faster.
	/// Often if you are comparing magnitudes of two vectors you can just compare their squared magnitudes.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	float SqrMagnitude();

	///	<returns>Returns a vector that is made from the smallest components of two vectors.</returns>
	static Vector2 Min(Vector2 lhs, Vector2 rhs);

	///	<returns>Returns a vector that is made from the largest components of two vectors.</returns>
	static Vector2 Max(Vector2 lhs, Vector2 rhs);

	///	<returns>Returns a formatted string for this vector.</returns>
	std::string ToString();

	/// <summary>prints a formatted string for this vector for easy debugging</summary>
	void DebugPrint();

	///	<returns>a Vector2 taking the x, y componets of the Vector3</returns>
	Vector3 ToVector3();

	/// <summary>Reflects a vector off the vector defined by a normal.</summary>
	///	<returns>Returns the reflected point</returns>
	static Vector2 Reflect(Vector2 inDirection, Vector2 inNormal);

	/// <summary>Returns the 2D vector perpendicular to this 2D vector.
	/// The result is always rotated 90-degrees in a counter-clockwise direction for a 2D coordinate system where the positive Y axis goes up.</summary>
	///	<returns>Vector2 The perpendicular direction.</returns>
	static Vector2 Perpendicular(Vector2 inDirection);

	/// <summary>Gets the unsigned angle in degrees between from and to. 
	/// The angle returned is the unsigned angle between the two vectors.
	/// Note: The angle returned will always be between 0 and 180 degrees, because the method returns the smallest angle between the vectors.
	/// That is, it will never return a reflex angle.
	/// Angles are calculated from world origin point(0, 0, 0) as the vertex.
	/// See Also : SignedAngle function.</summary>
	///	<returns>The unsigned angle in degrees between the two vectors.</returns>
	static float Angle(Vector2 from, Vector2 to);

	/// <summary>Gets the signed angle in degrees between from and to. 
	/// The angle returned is the signed counterclockwise angle between the two vectors.
	/// Note: The angle returned will always be between - 180 and 180 degrees, because the method returns the smallest angle between the vectors.
	/// That is, it will never return a reflex angle.
	/// Angles are calculated from world origin point(0, 0, 0) as the vertex.
	/// See Also : Angle function.</summary>
	///	<returns>The signed angle in degrees between the two vectors.</returns>
	static float SignedAngle(Vector2 from, Vector2 to);

	/// <summary> Linearly interpolates between vectors a and b by t.
	/// The parameter t is clamped to the range [0, 1]. 
	/// When t = 0 returns a.
	/// When t = 1 return b.
	/// When t = 0.5 returns the midpoint of a and b.</summary>
	///	<returns> returns the midpoint of a and b.</returns>
	static Vector2 Lerp(Vector2 a, Vector2 b, float t);

	/// <summary> Linearly interpolates between vectors a and b by t.
	/// The parameter t is clamped to the range [0, 1]. 
	/// When t = 0 returns a.
	/// When t = 1 return b.
	/// When t = 0.5 returns the midpoint of a and b.</summary>
	///	<returns> returns the midpoint of a and b.</returns>
	static Vector2 LerpUnclamped(Vector2 a, Vector2 b, float t);

	/// <summary>This is essentially the same as Vector2.
	/// Lerp but instead the function will ensure that the distance never exceeds maxDistanceDelta.
	/// Negative values of maxDistanceDelta pushes the vector away from target.</summary>
	///	<returns>Returns a point closer to the target</returns>
	static Vector2 MoveTowards(Vector2 current, Vector2 target, float maxDistanceDelta);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.</summary>
	///	<returns>Returns a point closer to the target</returns>
	static Vector2 SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime, float maxSpeed);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.</summary>
	///	<returns>Returns a point closer to the target</returns>
	static Vector2 SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime);

	/// <summary>Gradually changes a vector towards a desired goal over time. 
	/// The vector is smoothed by some spring - damper like function, which will never overshoot.</summary>
	///	<returns>Returns a point closer to the target</returns>
	static Vector2 SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime, float maxSpeed = FLT_MAX, float deltaTime = 0.03125f);
};

Vector2::Vector2()
{
	x = 0.f;
	y = 0.f;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2 Vector2::operator +(Vector2 b)
{
	return Vector2(x + b.x, y + b.y);
}

Vector2 Vector2::operator -(Vector2 b)
{
	return Vector2(x - b.x, y - b.y);
}

Vector2 Vector2::operator *(Vector2 b)
{
	return Vector2(x * b.x, y * b.y);
}

Vector2 Vector2::operator /(Vector2 b)
{
	return Vector2(x / b.x, y / b.y);
}

Vector2 Vector2::operator *(float d)
{
	return Vector2(x * d, y * d);
}

Vector2 Vector2::operator /(float d)
{
	return Vector2(x / d, y / d);
}

bool Vector2::operator ==(Vector2 rhs)
{
	float num = x - rhs.x;
	float num2 = y - rhs.y;
	return num * num + num2 * num2 < 9.9999994E-11f;
}

bool Vector2::operator !=(Vector2 rhs)
{
	return !(Vector2(x, y) == rhs);
}

Vector2 Vector2::Zero()
{
	return Vector2(0, 0);
}

Vector2 Vector2::One()
{
	return Vector2(1, 1);
}

Vector2 Vector2::Up()
{
	return Vector2(0.f, 1.f);
}

Vector2 Vector2::Down()
{
	return Vector2(0.f, -1.f);
}

Vector2 Vector2::Left()
{
	return Vector2(-1.f, 0.f);
}

Vector2 Vector2::Right()
{
	return Vector2(1.f, 0.f);
}

Vector2 Vector2::PositiveInfinity()
{
	return Vector2(FLT_MAX, FLT_MAX);
}

Vector2 Vector2::NegativeInfinity()
{
	return Vector2(FLT_MIN, FLT_MIN);
}

void Vector2::Set(float newX, float newY)
{
	x = newX;
	y = newY;
}

Vector2 Vector2::Scale(Vector2 a, Vector2 b)
{
	return Vector2(a.x * b.x, a.y * b.y);
}

void Vector2::Scale(Vector2 scale)
{
	x *= scale.x;
	y *= scale.y;
}

float Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Vector2::Dot(Vector2 rhs)
{
	return x * rhs.x + y * rhs.y;
}

Vector2 Vector2::Normalize(Vector2 value)
{
	float num = Magnitude(value);
	bool flag = num > 1E-05f;
	Vector2 result;
	if (flag)
	{
		result = value / num;
	}
	else
	{
		result = Vector2::Zero();
	}
	return result;
}

void Vector2::Normalize()
{
	float magnitude = Magnitude(Vector2(x, y));
	bool flag = magnitude > 1E-05f;
	if (flag)
	{
		x /= magnitude;
		y /= magnitude;
	}
	else
	{
		x = 0.f;
		y = 0.f;
	}
}

Vector2 Vector2::Normalized()
{
	return Normalize(Vector2(x, y));
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
	float num = a.x - b.x;
	float num2 = a.y - b.y;
	return (float)std::sqrt((double)(num * num + num2 * num2));
}

float Vector2::Distance(Vector2 b)
{
	float num = x - b.x;
	float num2 = y - b.y;
	return (float)std::sqrt((double)(num * num + num2 * num2));
}

Vector2 Vector2::ClampMagnitude(Vector2 vector, float maxLength)
{
	float sqrMagnitude = vector.SqrMagnitude();
	bool flag = sqrMagnitude > maxLength * maxLength;
	Vector2 result;
	if (flag)
	{
		float num = (float)std::sqrt((double)sqrMagnitude);
		float num2 = vector.x / num;
		float num3 = vector.y / num;
		result = Vector2(num2 * maxLength, num3 * maxLength);
	}
	else
	{
		result = vector;
	}
	return result;
}

float Vector2::Magnitude()
{
	return (float)std::sqrt((double)(x * x + y * y));
}

float Vector2::Magnitude(Vector2 a)
{
	return (float)std::sqrt((double)(a.x * a.x + a.y * a.y));
}

float Vector2::SqrMagnitude(Vector2 a)
{
	return a.x * a.x + a.y * a.y;
}

float Vector2::SqrMagnitude()
{
	return x * x + y * y;
}

Vector2 Vector2::Min(Vector2 lhs, Vector2 rhs)
{
	return Vector2(min(lhs.x, rhs.x), min(lhs.y, rhs.y));
}

Vector2 Vector2::Max(Vector2 lhs, Vector2 rhs)
{
	return Vector2(max(lhs.x, rhs.x), max(lhs.y, rhs.y));
}

std::string Vector2::ToString()
{
	char buffer[64];

	sprintf(buffer, "X:%f, Y:%f", x, y);

	return buffer;
}

void Vector2::DebugPrint()
{
	printf("X:%f, Y:%f\n", x, y);
}

Vector3 Vector2::ToVector3()
{
	return Vector3(x, y, 0.f);
}

Vector2 Vector2::Reflect(Vector2 inDirection, Vector2 inNormal)
{
	float num = -2.f * Dot(inNormal, inDirection);
	return Vector2(num * inNormal.x + inDirection.x, num * inNormal.y + inDirection.y);
}

Vector2 Vector2::Perpendicular(Vector2 inDirection)
{
	return Vector2(-inDirection.y, inDirection.x);
}

float Vector2::Angle(Vector2 from, Vector2 to)
{
	float num = (float)std::sqrt((double)(from.SqrMagnitude() * to.SqrMagnitude()));
	bool flag = num < 1E-15f;
	float result;
	if (flag)
	{
		result = 0.f;
	}
	else
	{
		float num2 = (Dot(from, to) / num);
		bool flag = num2 < -1.f;
		if (flag)
		{
			num2 = -1.f;
		}
		else
		{
			bool flag2 = num2 > 1.f;
			if (flag2)
			{
				num2 = 1.f;
			}
		}

		result = (float)std::acos((double)num2) * 57.29578f;
	}
	return result;
}

float Vector2::SignedAngle(Vector2 from, Vector2 to)
{
	float num = Angle(from, to);
	float num2 = (from.x * to.y - from.y * to.x >= 0.f) ? 1.f : -1.f;
	return num * num2;
}

Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
	bool flag = t < 0.f;
	float result;
	if (flag)
	{
		result = 0.f;
	}
	else
	{
		bool flag2 = t > 1.f;
		if (flag2)
		{
			result = 1.f;
		}
		else
		{
			result = t;
		}
	}
	t = result;
	return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

Vector2 Vector2::LerpUnclamped(Vector2 a, Vector2 b, float t)
{
	return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

Vector2 Vector2::MoveTowards(Vector2 current, Vector2 target, float maxDistanceDelta)
{
	float num = target.x - current.x;
	float num2 = target.y - current.y;
	float num3 = num * num + num2 * num2;
	bool flag = num3 == 0.f || (maxDistanceDelta >= 0.f && num3 <= maxDistanceDelta * maxDistanceDelta);
	Vector2 result;
	if (flag)
	{
		result = target;
	}
	else
	{
		float num4 = (float)std::sqrt((double)num3);
		result = Vector2(current.x + num / num4 * maxDistanceDelta, current.y + num2 / num4 * maxDistanceDelta);
	}
	return result;
}

Vector2 Vector2::SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime, float maxSpeed)
{
	float deltaTime = 0.03125f;//Time.deltaTime;
	return SmoothDamp(current, target, currentVelocity, smoothTime, maxSpeed, deltaTime);
}

Vector2 Vector2::SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime)
{
	float deltaTime = 0.03125f;// Time.deltaTime;
	float positiveInfinity = FLT_MAX;
	return SmoothDamp(current, target, currentVelocity, smoothTime, positiveInfinity, deltaTime);
}

Vector2 Vector2::SmoothDamp(Vector2 current, Vector2 target, Vector2& currentVelocity, float smoothTime, float maxSpeed, float deltaTime)
{
	smoothTime = max(0.0001f, smoothTime);
	float num = 2.f / smoothTime;
	float num2 = num * deltaTime;
	float num3 = 1.f / (1.f + num2 + 0.48f * num2 * num2 + 0.235f * num2 * num2 * num2);
	float num4 = current.x - target.x;
	float num5 = current.y - target.y;
	Vector2 vector = target;
	float num6 = maxSpeed * smoothTime;
	float num7 = num6 * num6;
	float num8 = num4 * num4 + num5 * num5;
	bool flag = num8 > num7;
	if (flag)
	{
		float num9 = (float)std::sqrt((double)num8);
		num4 = num4 / num9 * num6;
		num5 = num5 / num9 * num6;
	}
	target.x = current.x - num4;
	target.y = current.y - num5;
	float num10 = (currentVelocity.x + num * num4) * deltaTime;
	float num11 = (currentVelocity.y + num * num5) * deltaTime;
	currentVelocity.x = (currentVelocity.x - num * num10) * num3;
	currentVelocity.y = (currentVelocity.y - num * num11) * num3;
	float num12 = target.x + (num4 + num10) * num3;
	float num13 = target.y + (num5 + num11) * num3;
	float num14 = vector.x - current.x;
	float num15 = vector.y - current.y;
	float num16 = num12 - vector.x;
	float num17 = num13 - vector.y;
	bool flag2 = num14 * num16 + num15 * num17 > 0.f;
	if (flag2)
	{
		num12 = vector.x;
		num13 = vector.y;
		currentVelocity.x = (num12 - vector.x) / deltaTime;
		currentVelocity.y = (num13 - vector.y) / deltaTime;
	}
	return Vector2(num12, num13);
}

class Vector4
{
public:
	float x, y, z, w;

	/// <summary>Representation of four-dimensional vectors. 
	/// This structure is used in some places to represent four component vectors(e.g.mesh tangents, parameters for shaders).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector4(float _x, float _y, float _z, float _w);

	/// <summary>Representation of four-dimensional vectors. 
	/// This structure is used in some places to represent four component vectors(e.g.mesh tangents, parameters for shaders).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector4(float _x, float _y, float _z);

	/// <summary>Representation of four-dimensional vectors. 
	/// This structure is used in some places to represent four component vectors(e.g.mesh tangents, parameters for shaders).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector4(float _x, float _y);

	/// <summary>Representation of four-dimensional vectors. 
	/// This structure is used in some places to represent four component vectors(e.g.mesh tangents, parameters for shaders).
	/// In the majority of other cases a Vector3 is used.</summary>
	Vector4();

	/// <summary>Adds two vectors. 
	/// Adds corresponding components together.</summary>
	Vector4 operator +(Vector4 b);

	/// <summary>Subtracts one vector from another.
	/// Subtracts each component of b from a.</summary>
	Vector4 operator -(Vector4 b);

	/// <summary>Multiplies a vector by a number.
	/// Multiplies each component of a by a number d.</summary>
	Vector4 operator *(float d);

	/// <summary>Divides a vector by a number.
	/// Divides each component of a by a number d.</summary>
	Vector4 operator /(float d);

	/// <summary>To allow for floating point inaccuracies, the two vectors are considered equal if the magnitude of their difference is less than 1e-5.</summary>
	///	<returns>Returns true if two vectors are approximately equal.</returns>
	bool operator ==(Vector4 rhs);

	/// <summary>To allow for floating point inaccuracies, the two vectors are considered not equal if the magnitude of their difference is less than 1e-5.</summary>
	///	<returns>Returns true if two vectors are approximately not equal.</returns>
	bool operator !=(Vector4 rhs);

	/// <summary>Shorthand for writing Vector4(0,0,0,0).</summary>
	///	<returns>Returns Vector4(0,0,0,0)</returns>
	static Vector4 Zero();

	/// <summary>Shorthand for writing Vector4(1,1,1,1).</summary>
	///	<returns>Returns Vector4(1,1,1,1)</returns>
	static Vector4 One();

	/// <summary>Shorthand for writing Vector4(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX).</summary>
	///	<returns>Returns Vector4(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX)</returns>
	static Vector4 PositiveInfinity();

	/// <summary>Shorthand for writing Vector4(FLT_MIN, FLT_MIN, FLT_MIN, FLT_MIN).</summary>
	///	<returns>Returns Vector4(FLT_MIN, FLT_MIN, FLT_MIN, FLT_MIN)</returns>
	static Vector4 NegativeInfinity();

	/// <summary>Set x, y, z and w components of an existing Vector4.</summary>
	void Set(float newX, float newY, float newZ, float newW);

	/// <summary>Multiplies two vectors component-wise. 
	/// Every component in the result is a component of a multiplied by the same component of b.</summary>
	///	<returns>Returns the scaled vector</returns>
	static Vector4 Scale(Vector4 a, Vector4 b);

	/// <summary>Multiplies two vectors component-wise. 
	/// Every component in the result is a component of a multiplied by the same component of b.</summary>
	void Scale(Vector4 scale);

	/// <summary>Dot Product of two vectors.</summary>
	///	<returns>Returns lhs * rhs.</returns>
	static float Dot(Vector4 a, Vector4 b);

	/// <summary>Dot Product of two vectors.</summary>
	///	<returns>Returns this * rhs.</returns>
	float Dot(Vector4 b);

	/// <summary>Makes this vector have a magnitude of 1.
	/// Note that this function will change the current vector.
	/// If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	///	<returns>Returns the normalized vector</returns>
	static Vector4 Normalize(Vector4 a);

	/// <summary>Makes this vector have a magnitude of 1.
	/// Note that this function will change the current vector.
	/// If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	void Normalize();

	/// <summary>Makes this vector have a magnitude of 1.
	/// Note that this function will change the current vector.
	/// If you want to keep the current vector unchanged, use normalized variable.
	/// If this vector is too small to be normalized it will be set to zero.</summary>
	///	<returns>Returns the normalized vector</returns>
	Vector4 Normalized();

	///	<returns>Returns the distance between a and b.</returns>
	static float Distance(Vector4 a, Vector4 b);

	///	<returns>Returns the distance between a and b.</returns>
	float Distance(Vector4 b);

	/// <summary>The length of the vector is square root of (x*x+y*y+z*z+w*w).
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	///	<returns>Returns the length of this vector </returns>
	static float Magnitude(Vector4 a);

	/// <summary>The length of the vector is square root of (x*x+y*y+z*z+w*w).
	/// If you only need to compare magnitudes of some vectors, you can compare squared magnitudes of them using sqrMagnitude(computing squared magnitudes is faster).</summary>
	///	<returns>Returns the length of this vector </returns>
	float Magnitude();

	/// <summary>Calculating the squared magnitude instead of the magnitude is much faster.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	static float SqrMagnitude(Vector4 a);

	/// <summary>Calculating the squared magnitude instead of the magnitude is much faster.</summary>
	///	<returns>Returns the squared length of this vector</returns>
	float SqrMagnitude();

	///	<returns>Returns a vector that is made from the smallest components of two vectors.</returns>
	static Vector4 Min(Vector4 lhs, Vector4 rhs);

	///	<returns>Returns a vector that is made from the largest components of two vectors.</returns>
	static Vector4 Max(Vector4 lhs, Vector4 rhs);

	///	<returns>Returns a formatted string for this vector.</returns>
	std::string ToString();

	///	<returns>Prints the current values stored in this vector</returns>
	void DebugPrint();

	///	<returns>Returns A Vector2 made of the x, y componets of the vector</returns>
	Vector2 ToVector2();

	///	<returns>Returns A Vector3 made of the x, y, z componets of the vector</returns>
	Vector3 ToVector3();

	/// <summary>Projects a vector onto another vector.</summary>
	///	<returns>Returns a projected onto b.</returns>
	static Vector4 Project(Vector4 a, Vector4 b);

	/// <summary>Linearly interpolates between two vectors.
	/// Interpolates between and b by amount t.
	/// The parameter t is clamped between[0...1].
	/// When t = 0 returns a.
	/// When t = 1 returns b.
	/// When t = 0.5 </summary>
	///	<returns>returns the midpoint of a and b.</returns>
	static Vector4 Lerp(Vector4 a, Vector4 b, float t);

	/// <summary>Linearly interpolates between two vectors.
	/// Interpolates between and b by amount t.
	/// The parameter t is clamped between[0...1].
	/// When t = 0 returns a.
	/// When t = 1 returns b.
	/// When t = 0.5 </summary>
	///	<returns>returns the midpoint of a and b.</returns>
	static Vector4 LerpUnclamped(Vector4 a, Vector4 b, float t);

	/// <summary>Moves a point current towards target.
	/// This is essentially the same as Vector4.Lerp but instead the function will ensure that the speed never exceeds maxDistanceDelta.Negative values of maxDistanceDelta pushes the vector away from target.</summary>
	///	<returns>Returns a point slightly closer to b.</returns>
	static Vector4 MoveTowards(Vector4 current, Vector4 target, float maxDistanceDelta);
};

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::Vector4(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
	w = 0.f;
}

Vector4::Vector4(float _x, float _y)
{
	x = _x;
	y = _y;
	z = 0.f;
	w = 0.f;
}

Vector4::Vector4()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
}

Vector4 Vector4::operator +(Vector4 b)
{
	return Vector4(x + b.x, y + b.y, z + b.z, w + b.w);
}

Vector4 Vector4::operator -(Vector4 b)
{
	return Vector4(x - b.x, y - b.y, z - b.z, w - b.w);
}

Vector4 Vector4::operator *(float d)
{
	return Vector4(x * d, y * d, z * d, w * d);
}

Vector4 Vector4::operator /(float d)
{
	return Vector4(x / d, y / d, z / d, w / d);
}

bool Vector4::operator ==(Vector4 rhs)
{
	float num = x - rhs.x;
	float num2 = y - rhs.y;
	float num3 = z - rhs.z;
	float num4 = w - rhs.w;
	float num5 = num * num + num2 * num2 + num3 * num3 + num4 * num4;
	return num5 < 9.9999994E-11f;
}

bool Vector4::operator !=(Vector4 rhs)
{
	return !(Vector4(x, y, z, w) == rhs);
}

Vector4 Vector4::Zero()
{
	return Vector4(0, 0, 0, 0);
}

Vector4 Vector4::One()
{
	return Vector4(1.f, 1.f, 1.f, 1.f);
}

Vector4 Vector4::PositiveInfinity()
{
	return Vector4(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX);
}

Vector4 Vector4::NegativeInfinity()
{
	return Vector4(FLT_MIN, FLT_MIN, FLT_MIN, FLT_MIN);
}

void Vector4::Set(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

Vector4 Vector4::Scale(Vector4 a, Vector4 b)
{
	return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

void Vector4::Scale(Vector4 scale)
{
	x *= scale.x;
	y *= scale.y;
	z *= scale.z;
	w *= scale.w;
}

float Vector4::Dot(Vector4 a, Vector4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float Vector4::Dot(Vector4 b)
{
	return x * b.x + y * b.y + z * b.z + w * b.w;
}

Vector4 Vector4::Normalize(Vector4 a)
{
	float num = Magnitude(a);
	bool flag = num > 1E-05f;
	Vector4 result;
	if (flag)
	{
		result = a / num;
	}
	else
	{
		result = Vector4(0, 0, 0, 0);
	}
	return result;
}

void Vector4::Normalize()
{
	float num = Vector4::Magnitude(Vector4(x, y, z, w));
	bool flag = num > 1E-05f;
	if (flag)
	{
		x /= num;
		y /= num;
		z /= num;
		w /= num;
	}
	else
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
		w = 0.f;
	}
}

Vector4 Vector4::Normalized()
{
	return Normalize(Vector4(x, y, z, w));
}

float Vector4::Distance(Vector4 a, Vector4 b)
{
	return Magnitude(a - b);
}

float Vector4::Distance(Vector4 b)
{
	return Magnitude(Vector4(x, y, z, w) - b);
}

float Vector4::Magnitude(Vector4 a)
{
	return (float)std::sqrt((double)Dot(a, a));
}

float Vector4::Magnitude()
{
	return (float)std::sqrt((double)Dot(Vector4(x, y, z, w), Vector4(x, y, z, w)));
}

float Vector4::SqrMagnitude(Vector4 a)
{
	return Dot(a, a);
}

float Vector4::SqrMagnitude()
{
	return Dot(Vector4(x, y, z, w), Vector4(x, y, z, w));
}

Vector4 Vector4::Min(Vector4 lhs, Vector4 rhs)
{
	return Vector4(min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z), min(lhs.w, rhs.w));
}

Vector4 Vector4::Max(Vector4 lhs, Vector4 rhs)
{
	return Vector4(max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z), max(lhs.w, rhs.w));
}

std::string Vector4::ToString()
{
	char buffer[64];

	sprintf(buffer, "X:%f, Y:%f Z:%f W:%f", x, y, z, w);

	return buffer;
}

void Vector4::DebugPrint()
{
	printf("X:%f, Y:%f Z:%f W:%f\n", x, y, z, w);
}

Vector2 Vector4::ToVector2()
{
	return Vector2(x, y);
}

Vector3 Vector4::ToVector3()
{
	return Vector3(x, y, z);
}

Vector4 Vector4::Project(Vector4 a, Vector4 b)
{
	return b * (Dot(a, b) / Dot(b, b));
}

Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float t)
{
	bool flag = t < 0.f;
	float result;
	if (flag)
	{
		result = 0.f;
	}
	else
	{
		bool flag2 = t > 1.f;
		if (flag2)
		{
			result = 1.f;
		}
		else
		{
			result = t;
		}
	}

	t = result;
	return Vector4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
}

Vector4 Vector4::LerpUnclamped(Vector4 a, Vector4 b, float t)
{
	return Vector4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
}

Vector4 Vector4::MoveTowards(Vector4 current, Vector4 target, float maxDistanceDelta)
{
	float num = target.x - current.x;
	float num2 = target.y - current.y;
	float num3 = target.z - current.z;
	float num4 = target.w - current.w;
	float num5 = num * num + num2 * num2 + num3 * num3 + num4 * num4;
	bool flag = num5 == 0.f || (maxDistanceDelta >= 0.f && num5 <= maxDistanceDelta * maxDistanceDelta);
	Vector4 result;
	if (flag)
	{
		result = target;
	}
	else
	{
		float num6 = (float)std::sqrt((double)num5);
		result = Vector4(current.x + num / num6 * maxDistanceDelta, current.y + num2 / num6 * maxDistanceDelta, current.z + num3 / num6 * maxDistanceDelta, current.w + num4 / num6 * maxDistanceDelta);
	}
	return result;
}

class Quaternion
{
public:
	float x, y, z, w;

	/// <summary>Quaternions are used to represent rotations.
	/// They are compact, don't suffer from gimbal lock and can easily be interpolated.
	/// Unity internally uses Quaternions to represent all rotations.
	/// They are based on complex numbers and are not easy to understand intuitively.
	/// You almost never access or modify individual Quaternion components(x, y, z, w); most often you would just take existing rotations(e.g.from the Transform) and use them to construct new rotations(e.g.to smoothly interpolate between two rotations).
	/// The Quaternion functions that you use 99 % of the time are : Quaternion.LookRotation, Quaternion.Angle, Quaternion.Euler, Quaternion.Slerp, Quaternion.FromToRotation, and Quaternion.identity.
	/// (The other functions are only for exotic uses.) You can use the Quaternion.operator * to rotate one rotation by another, or to rotate a vector by a rotation.</summary>
	Quaternion(float _x, float _y, float _z, float _w);

	/// <summary>Quaternions are used to represent rotations.
	/// They are compact, don't suffer from gimbal lock and can easily be interpolated.
	/// Unity internally uses Quaternions to represent all rotations.
	/// They are based on complex numbers and are not easy to understand intuitively.
	/// You almost never access or modify individual Quaternion components(x, y, z, w); most often you would just take existing rotations(e.g.from the Transform) and use them to construct new rotations(e.g.to smoothly interpolate between two rotations).
	/// The Quaternion functions that you use 99 % of the time are : Quaternion.LookRotation, Quaternion.Angle, Quaternion.Euler, Quaternion.Slerp, Quaternion.FromToRotation, and Quaternion.identity.
	/// (The other functions are only for exotic uses.) You can use the Quaternion.operator * to rotate one rotation by another, or to rotate a vector by a rotation.</summary>
	Quaternion();

	/// <summary>This quaternion corresponds to "no rotation" - the object is perfectly aligned with the world or parent axes.</summary>
	static Quaternion Identity();

	/// <summary>Set x, y, z and w components of an existing Quaternion.</summary>
	void Set(float newX, float newY, float newZ, float newW);

	/// <summary>Combines rotations lhs and rhs.
	/// Rotating by the product lhs* rhs is the same as applying the two rotations in sequence : lhs firstand then rhs, relative to the reference frame resulting from lhs rotation.
	/// Note that this means rotations are not commutative, so lhs* rhs does not give the same rotation as rhs* lhs.</summary>
	Quaternion operator *(Quaternion rhs);

	/// <summary>Rotates the point point with rotation.</summary>
	Vector3 operator *(Vector3 point);
	
	/// <summary>Are two quaternions equal to each other? 
	/// This function tests whether dot product of two quaternions is close to 1.0.</summary>
	bool operator ==(Quaternion rhs);

	/// <summary>Are two quaternions equal to each other? 
	/// This function tests whether dot product of two quaternions is not close to 1.0.</summary>
	bool operator !=(Quaternion rhs);

	/// <summary>Are two quaternions equal to each other? 
	/// This function tests whether dot product of two quaternions is close to 1.0.</summary>
	static bool IsEqualUsingDot(float dot);

	///	<returns>The dot product between two rotations.</returns>
	static float Dot(Quaternion a, Quaternion b);

	///	<returns>Returns the length of the quaternion squared</returns>
	float LengthSquared();

	/// <summary>Converts this quaternion to one with the same orientation but with a magnitude of 1. 
	/// When normalized, a quaternion keeps the same orientation but its magnitude is 1.0.
	/// Note that this method will change the current quaternion.
	/// If you want to keep the current quaternion unchanged, use the normalized property instead. 
	/// If this quaternion is too small to be normalized it will be set to Quaternion.identity.</summary>
	static Quaternion Normalize(Quaternion q);

	/// <summary>Converts this quaternion to one with the same orientation but with a magnitude of 1. 
	/// When normalized, a quaternion keeps the same orientation but its magnitude is 1.0.
	/// Note that this method will change the current quaternion.
	/// If you want to keep the current quaternion unchanged, use the normalized property instead. 
	/// If this quaternion is too small to be normalized it will be set to Quaternion.identity.</summary>
	void Normalize();

	/// <summary>Converts this quaternion to one with the same orientation but with a magnitude of 1. 
	/// When normalized, a quaternion keeps the same orientation but its magnitude is 1.0.
	/// Note that this method will change the current quaternion.
	/// If you want to keep the current quaternion unchanged, use the normalized property instead. 
	/// If this quaternion is too small to be normalized it will be set to Quaternion.identity.</summary>
	Quaternion Normalized();

	/// <summary>Creates a rotation which rotates from fromDirection to toDirection. 
	/// Usually you use this to rotate a transform so that one of its axes eg.the y - axis - follows a target direction toDirection in world space.</summary>
	static Quaternion FromToRotation(Vector3 fromDirection, Vector3 toDirection);

	///	<returns>Returns the Inverse of rotation.</returns>
	static Quaternion Inverse(Quaternion rotation);

	/// <summary>Spherically interpolates between quaternions a and b by ratio t. The parameter t is clamped to the range [0, 1].
	/// Use this to create a rotation which smoothly interpolates between the first quaternion a to the second quaternion b, based on the value of the parameter t.
	/// If the value of the parameter is close to 0, the output will be close to a, if it is close to 1, the output will be close to b.</summary>
	static Quaternion Slerp(Quaternion a, Quaternion b, float t);

	/// <summary>Spherically interpolates between quaternions a and b by ratio t. The parameter t is clamped to the range [0, 1].
	/// Use this to create a rotation which smoothly interpolates between the first quaternion a to the second quaternion b, based on the value of the parameter t.
	/// If the value of the parameter is close to 0, the output will be close to a, if it is close to 1, the output will be close to b.</summary>
	static Quaternion SlerpUnclamped(Quaternion a, Quaternion b, float t);

	/// <summary>Interpolates between a and b by t and normalizes the result afterwards. The parameter t is clamped to the range [0, 1].
	/// This is faster than Slerp but looks worse if the rotations are far apart.</summary>
	static Quaternion Lerp(Quaternion a, Quaternion b, float t);

	/// <summary>Interpolates between a and b by t and normalizes the result afterwards. The parameter t is clamped to the range [0, 1].
	/// This is faster than Slerp but looks worse if the rotations are far apart.</summary>
	static Quaternion LerpUnclamped(Quaternion a, Quaternion b, float t);

	/// <summary>Creates a rotation which rotates angle degrees around axis.
	/// For more information see Rotationand Orientation in Unity.
	/// The magnitude of the axis parameter is not applied.</summary>
	static Quaternion AngleAxis(float angle, Vector3 axis);

	/// <summary>Creates a rotation with the specified forward and upwards directions. 
	/// Z axis will be aligned with forward, X axis aligned with cross product between forwardand upwards, and Y axis aligned with cross product between Zand X.</summary>
	///	<returns>Returns identity if the magnitude of forward is zero. If forwardand upwards are colinear, or if the magnitude of upwards is zero, the result is the same as Quaternion.FromToRotation with fromDirection set to the positive Z - axis(0, 0, 1) and toDirection set to the normalized forwards direction.</returns>
	static Quaternion LookRotation(Vector3 forward, Vector3 upwards = Vector3::Up());

	/// <summary>Creates a rotation with the specified forward and upwards directions. 
	/// Z axis will be aligned with forward, X axis aligned with cross product between forwardand upwards, and Y axis aligned with cross product between Zand X.</summary>
	///	<returns>Returns identity if the magnitude of forward is zero. If forwardand upwards are colinear, or if the magnitude of upwards is zero, the result is the same as Quaternion.FromToRotation with fromDirection set to the positive Z - axis(0, 0, 1) and toDirection set to the normalized forwards direction.</returns>
	static Quaternion LookRotation(Vector3 forward);

	/// <summary>Creates a rotation with the specified forward and upwards directions. 
	/// The result is applied to this quaternion.
	/// If used to orient a Transform, the Z axis will be aligned with forward / and the Y axis with upwards, assuming these vectors are orthogonal.
	/// Logs an error if the forward direction is zero.</summary>
	void SetLookRotation(Vector3 view);

	/// <summary>Creates a rotation with the specified forward and upwards directions. 
	/// The result is applied to this quaternion.
	/// If used to orient a Transform, the Z axis will be aligned with forward / and the Y axis with upwards, assuming these vectors are orthogonal.
	/// Logs an error if the forward direction is zero.</summary>
	void SetLookRotation(Vector3 view, Vector3 up = Vector3::Up());

	///	<returns>Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis, and y degrees around the y axis; applied in that order.</returns>
	static Quaternion Euler(float x, float y, float z);

	///	<returns>Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis, and y degrees around the y axis.</returns>
	static Quaternion Euler(Vector3 euler);

	///	<returns>Returns the euler angle representation of the rotation.</returns>
	Vector3 EulerAngles();

	/// <summary>Example: Think of two GameObjects (A and B) moving around a third GameObject (C). Lines from C to A and C to B create a triangle which can change over time. The angle between CA and CB is the value Quaternion.Angle provides.</summary>
	///	<returns>Returns the angle in degrees between two rotations a and b.</returns>
	static float Angle(Quaternion a, Quaternion b);

	/// <summary>Converts a rotation to angle-axis representation (angles in degrees).</summary>
	void ToAngleAxis(float& angle, Vector3& axis);

	/// <summary>Creates a rotation which rotates from fromDirection to toDirection. 
	/// Use this to create a rotation which starts at the first Vector(fromDirection) and rotates to the second Vector(toDirection).
	/// These Vectors must be set up in a script.</summary>
	void SetFromToRotation(Vector3 fromDirection, Vector3 toDirection);

	/// <summary>Rotates a rotation from towards to. 
	/// The from quaternion is rotated towards to by an angular step of maxDegreesDelta(but note that the rotation will not overshoot).
	/// Negative values of maxDegreesDelta will move away from to until the rotation is exactly the opposite direction.</summary>
	static Quaternion RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta);

	///	<returns>Returns a formatted string for this quaternion.</returns>
	std::string ToString();

	/// <summary>Prints a formatted string for this quaternion.</summary>
	void DebugPrint();

	///	<returns>Retuns the x, y, z componets of this quaternion</returns>
	Vector3 ToVector3();
private:
	static Quaternion Internal_FromEulerRad_Injected(Vector3 euler);
	static Vector3 Internal_ToEulerRad_Injected(Quaternion rotation);
	static Vector3 Internal_MakePositive(Vector3 euler);
	static Quaternion Slerp_Injected(Quaternion& a, Quaternion& b, float t);
	static Quaternion SlerpUnclamped_Injected(Quaternion& a, Quaternion& b, float t);
	static void Internal_ToAxisAngleRad_Injected(Quaternion q, Vector3& axis, float& angle);
	static Quaternion AngleAxis_Injected(float degress, Vector3& axis);
	static Quaternion LookRotation_Injected(Vector3& forward, Vector3& up);
	static Quaternion Internal_FromEulerRad(Vector3 euler);
	static Vector3 Internal_ToEulerRad(Quaternion rotation);
	static void Internal_ToAxisAngleRad(Quaternion q, Vector3& axis, float& angle);
	static Vector3 NormalizeAngles(Vector3 angles);
	static float NormalizeAngle(float angle);
};

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Quaternion::Quaternion()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
}

Quaternion Quaternion::Identity()
{
	return Quaternion(0.f, 0.f, 0.f, 1.f);
}

void Quaternion::Set(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

Quaternion Quaternion::operator *(Quaternion rhs)
{
	return Quaternion(w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y, w * rhs.y + y * rhs.w + z * rhs.x - x * rhs.z, w * rhs.z + z * rhs.w + x * rhs.y - y * rhs.x, w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z);
}

Vector3 Quaternion::operator *(Vector3 point)
{
	float num = x * 2.f;
	float num2 = y * 2.f;
	float num3 = z * 2.f;
	float num4 = x * num;
	float num5 = y * num2;
	float num6 = z * num3;
	float num7 = x * num2;
	float num8 = x * num3;
	float num9 = y * num3;
	float num10 = w * num;
	float num11 = w * num2;
	float num12 = w * num3;
	Vector3 result;
	result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
	result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
	result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
	return result;
}

bool Quaternion::operator ==(Quaternion rhs)
{
	return IsEqualUsingDot(Dot(Quaternion(x, y, z, w), rhs));
}

bool Quaternion::operator !=(Quaternion rhs)
{
	return !(Quaternion(x, y, z, w) == rhs);
}

bool Quaternion::IsEqualUsingDot(float dot)
{
	return dot > 0.999999f;
}

float Quaternion::Dot(Quaternion a, Quaternion b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float Quaternion::LengthSquared()
{
	return x * x + y * y + z * z + w * w;
}

Quaternion Quaternion::Normalize(Quaternion q)
{
	float num = std::sqrt(Dot(q, q));
	bool flag = num < FLT_EPSILON;
	Quaternion result;
	if (flag)
	{
		result = Identity();
	}
	else
	{
		result = Quaternion(q.x / num, q.y / num, q.z / num, q.w / num);
	}
	return result;
}

void Quaternion::Normalize()
{
	Quaternion current = Normalize(Quaternion(x, y, z, w));
	x = current.x;
	y = current.y;
	z = current.z;
	w = current.w;
}

Quaternion Quaternion::Normalized()
{
	return Normalize(Quaternion(x, y, z, w));
}

Quaternion Quaternion::FromToRotation(Vector3 fromDirection, Vector3 toDirection)
{
	return RotateTowards(LookRotation(fromDirection, Vector3::Up()), LookRotation(toDirection, Vector3::Up()), FLT_MAX);
}

Quaternion Quaternion::Inverse(Quaternion rotation)
{
	float lengthSq = rotation.LengthSquared();
	if (lengthSq != 0.0)
	{
		float i = 1.0f / lengthSq;

		return Quaternion(rotation.x * -1.f, rotation.x * -1.f, rotation.x * -1.f, rotation.w * i);
	}
	return rotation;
}

Quaternion Quaternion::Slerp(Quaternion a, Quaternion b, float t)
{
	return Slerp_Injected(a, b, t);
}

Quaternion Quaternion::SlerpUnclamped(Quaternion a, Quaternion b, float t)
{
	return SlerpUnclamped_Injected(a, b, t);
}

Quaternion Quaternion::Lerp(Quaternion a, Quaternion b, float t)
{
	if (t > 1) t = 1;
	if (t < 0) t = 0;
	return Slerp_Injected(a, b, t);
}

Quaternion Quaternion::LerpUnclamped(Quaternion a, Quaternion b, float t)
{
	return Slerp_Injected(a, b, t);
}

Quaternion Quaternion::AngleAxis(float angle, Vector3 axis)
{
	return AngleAxis_Injected(angle, axis);
}

Quaternion Quaternion::LookRotation(Vector3 forward, Vector3 upwards)
{
	return LookRotation_Injected(forward, upwards);
}

Quaternion Quaternion::LookRotation(Vector3 forward)
{
	return LookRotation(forward, Vector3::Up());
}

void Quaternion::SetLookRotation(Vector3 view)
{
	SetLookRotation(view, Vector3::Up());
}

void Quaternion::SetLookRotation(Vector3 view, Vector3 up)
{
	Quaternion current = LookRotation(view, up);
	x = current.x;
	y = current.y;
	z = current.z;
	w = current.w;
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
	return Internal_FromEulerRad(Vector3(x, y, z) * 0.017453292f);
}

Quaternion Quaternion::Euler(Vector3 euler)
{
	return Internal_FromEulerRad(euler * 0.017453292f);
}

Vector3 Quaternion::EulerAngles()
{
	return Internal_MakePositive(Internal_ToEulerRad(Quaternion(x, y, z, w)) * 57.29578f);
}

float Quaternion::Angle(Quaternion a, Quaternion b)
{
	float num = Dot(a, b);
	return IsEqualUsingDot(num) ? 0.f : (std::acos(min(std::abs(num), 1.f)) * 2.f * 57.29578f);
}

void Quaternion::ToAngleAxis(float& angle, Vector3& axis)
{
	Internal_ToAxisAngleRad(Quaternion(x, y, z, w), axis, angle);
	angle *= 57.29578f;
}

void Quaternion::SetFromToRotation(Vector3 fromDirection, Vector3 toDirection)
{
	Quaternion current = FromToRotation(fromDirection, toDirection);
	x = current.x;
	y = current.y;
	z = current.z;
	w = current.w;
}

Quaternion Quaternion::RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta)
{
	float num = Angle(from, to);
	bool flag = num == 0.f;
	Quaternion result;
	if (flag)
	{
		result = to;
	}
	else
	{
		result = SlerpUnclamped(from, to, min(1.f, maxDegreesDelta / num));
	}
	return result;
}

std::string Quaternion::ToString()
{
	char buffer[64];

	sprintf(buffer, "X:%f, Y:%f Z:%f W:%f\n", x, y, z, w);

	return buffer;
}

void Quaternion::DebugPrint()
{
	printf("X:%f, Y:%f Z:%f W:%f\n", x, y, z, w);
}

Vector3 Quaternion::ToVector3()
{
	return Vector3(x, y, z);
}

Quaternion Quaternion::Internal_FromEulerRad_Injected(Vector3 euler)
{
	auto yaw = euler.x;
	auto pitch = euler.y;
	auto roll = euler.z;
	float rollOver2 = roll * 0.5f;
	float sinRollOver2 = (float)std::sin((double)rollOver2);
	float cosRollOver2 = (float)std::cos((double)rollOver2);
	float pitchOver2 = pitch * 0.5f;
	float sinPitchOver2 = (float)std::sin((double)pitchOver2);
	float cosPitchOver2 = (float)std::cos((double)pitchOver2);
	float yawOver2 = yaw * 0.5f;
	float sinYawOver2 = (float)std::sin((double)yawOver2);
	float cosYawOver2 = (float)std::cos((double)yawOver2);
	Quaternion result;
	result.x = cosYawOver2 * cosPitchOver2 * cosRollOver2 + sinYawOver2 * sinPitchOver2 * sinRollOver2;
	result.y = cosYawOver2 * cosPitchOver2 * sinRollOver2 - sinYawOver2 * sinPitchOver2 * cosRollOver2;
	result.z = cosYawOver2 * sinPitchOver2 * cosRollOver2 + sinYawOver2 * cosPitchOver2 * sinRollOver2;
	result.w = sinYawOver2 * cosPitchOver2 * cosRollOver2 - cosYawOver2 * sinPitchOver2 * sinRollOver2;
	return result;
}

Vector3 Quaternion::Internal_ToEulerRad_Injected(Quaternion rotation)
{
	float sqw = rotation.w * rotation.w;
	float sqx = rotation.x * rotation.x;
	float sqy = rotation.y * rotation.y;
	float sqz = rotation.z * rotation.z;
	float unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
	float test = rotation.x * rotation.w - rotation.y * rotation.z;
	Vector3 v;

	if (test > 0.4995f * unit)
	{ // singularity at north pole
		v.y = 2.f * atan2(rotation.y, rotation.x);
		v.x = M_PI / 2.f;
		v.z = 0;
		return NormalizeAngles(v * M_RADPI);
	}
	if (test < -0.4995f * unit)
	{ // singularity at south pole
		v.y = -2.f * atan2(rotation.y, rotation.x);
		v.x = -M_PI / 2.f;
		v.z = 0;
		return NormalizeAngles(v * M_RADPI);
	}
	Quaternion q = Quaternion(rotation.w, rotation.z, rotation.x, rotation.y);
	v.y = (float)atan2(2.f * q.x * q.w + 2.f * q.y * q.z, 1 - 2.f * (q.z * q.z + q.w * q.w));     // Yaw
	v.x = (float)asin(2.f * (q.x * q.z - q.w * q.y));                             // Pitch
	v.z = (float)atan2(2.f * q.x * q.y + 2.f * q.z * q.w, 1 - 2.f * (q.y * q.y + q.z * q.z));      // Roll
	return NormalizeAngles(v * M_RADPI);
}

Vector3 Quaternion::Internal_MakePositive(Vector3 euler)
{
	float num = -0.005729578f;
	float num2 = 360.f + num;
	bool flag = euler.x < num;
	if (flag)
	{
		euler.x += 360.f;
	}
	else
	{
		bool flag2 = euler.x > num2;
		if (flag2)
		{
			euler.x -= 360.f;
		}
	}
	bool flag3 = euler.y < num;
	if (flag3)
	{
		euler.y += 360.f;
	}
	else
	{
		bool flag4 = euler.y > num2;
		if (flag4)
		{
			euler.y -= 360.f;
		}
	}
	bool flag5 = euler.z < num;
	if (flag5)
	{
		euler.z += 360.f;
	}
	else
	{
		bool flag6 = euler.z > num2;
		if (flag6)
		{
			euler.z -= 360.f;
		}
	}
	return euler;
}

Quaternion Quaternion::Slerp_Injected(Quaternion& a, Quaternion& b, float t)
{
	if (t > 1) t = 1;
	if (t < 0) t = 0;
	return SlerpUnclamped_Injected(a, b, t);
}

Quaternion Quaternion::SlerpUnclamped_Injected(Quaternion& a, Quaternion& b, float t)
{
	// if either input is zero, return the other.
	if (a.LengthSquared() == 0.0f)
	{
		if (b.LengthSquared() == 0.0f)
		{
			return Identity();
		}
		return b;
	}
	else if (b.LengthSquared() == 0.0f)
	{
		return a;
	}

	float cosHalfAngle = a.w * b.w + Vector3::Dot(a.ToVector3(), b.ToVector3());

	if (cosHalfAngle >= 1.0f || cosHalfAngle <= -1.0f)
	{
		// angle = 0.0f, so just return one input.
		return a;
	}
	else if (cosHalfAngle < 0.0f)
	{
		b.x = -b.x;
		b.y = -b.y;
		b.z = -b.z;
		b.w = -b.w;
		cosHalfAngle = -cosHalfAngle;
	}

	float blendA;
	float blendB;
	if (cosHalfAngle < 0.99f)
	{
		// do proper slerp for big angles
		float halfAngle = (float)std::acos(cosHalfAngle);
		float sinHalfAngle = (float)std::sin(halfAngle);
		float oneOverSinHalfAngle = 1.0f / sinHalfAngle;
		blendA = (float)std::sin(halfAngle * (1.0f - t)) * oneOverSinHalfAngle;
		blendB = (float)std::sin(halfAngle * t) * oneOverSinHalfAngle;
	}
	else
	{
		// do lerp if angle is really small.
		blendA = 1.0f - t;
		blendB = t;
	}

	Vector3 vec = a.ToVector3() * blendA + b.ToVector3() * blendB;
	Quaternion result = Quaternion(vec.x, vec.y, vec.z, blendA * a.w + blendB * b.w);
	if (result.LengthSquared() > 0.0f)
	{
		return Normalize(result);
	}
	else
	{
		return Identity();
	}
}

void Quaternion::Internal_ToAxisAngleRad_Injected(Quaternion q, Vector3& axis, float& angle)
{
	if (std::abs(q.w) > 1.0f)
	{
		q.Normalize();
	}


	angle = 2.0f * (float)std::acos(q.w); // angle
	float den = (float)std::sqrt(1.0 - q.w * q.w);
	if (den > 0.0001f)
	{
		axis = q.ToVector3() / den;
	}
	else
	{
		// This occurs when the angle is zero. 
		// Not a problem: just set an arbitrary normalized axis.
		axis = Vector3(1, 0, 0);
	}
}

Quaternion Quaternion::AngleAxis_Injected(float degress, Vector3& axis)
{
	if (axis.SqrMagnitude() == 0.0f)
	{
		return Identity();
	}

	Quaternion result = Identity();
	auto radians = degress * M_RADPI;
	radians *= 0.5f;
	axis.Normalize();
	axis = axis * (float)std::sin(radians);
	result.x = axis.x;
	result.y = axis.y;
	result.z = axis.z;
	result.w = (float)std::cos(radians);

	return Normalize(result);
}

Quaternion Quaternion::LookRotation_Injected(Vector3& forward, Vector3& up)
{
	Vector3 vector = Vector3::Normalize(forward);
	Vector3 vector2 = Vector3::Normalize(Vector3::Cross(up, vector));
	Vector3 vector3 = Vector3::Cross(vector, vector2);
	float m00 = vector2.x;
	float m01 = vector2.y;
	float m02 = vector2.z;
	float m10 = vector3.x;
	float m11 = vector3.y;
	float m12 = vector3.z;
	float m20 = vector.x;
	float m21 = vector.y;
	float m22 = vector.z;

	float num8 = (m00 + m11) + m22;
	Quaternion quaternion = {};
	if (num8 > 0.f)
	{
		float num = (float)sqrt(num8 + 1.f);
		quaternion.w = num * 0.5f;
		num = 0.5f / num;
		quaternion.x = (m12 - m21) * num;
		quaternion.y = (m20 - m02) * num;
		quaternion.z = (m01 - m10) * num;
		return quaternion;
	}
	if ((m00 >= m11) && (m00 >= m22))
	{
		float num7 = (float)sqrt(((1.f + m00) - m11) - m22);
		float num4 = 0.5f / num7;
		quaternion.x = 0.5f * num7;
		quaternion.y = (m01 + m10) * num4;
		quaternion.z = (m02 + m20) * num4;
		quaternion.w = (m12 - m21) * num4;
		return quaternion;
	}
	if (m11 > m22)
	{
		float num6 = (float)sqrt(((1.f + m11) - m00) - m22);
		float num3 = 0.5f / num6;
		quaternion.x = (m10 + m01) * num3;
		quaternion.y = 0.5f * num6;
		quaternion.z = (m21 + m12) * num3;
		quaternion.w = (m20 - m02) * num3;
		return quaternion;
	}
	float num5 = (float)sqrt(((1.f + m22) - m00) - m11);
	float num2 = 0.5f / num5;
	quaternion.x = (m20 + m02) * num2;
	quaternion.y = (m21 + m12) * num2;
	quaternion.z = 0.5f * num5;
	quaternion.w = (m01 - m10) * num2;
	return quaternion;
}

Quaternion Quaternion::Internal_FromEulerRad(Vector3 euler)
{
	return Internal_FromEulerRad_Injected(euler);
}

Vector3 Quaternion::Internal_ToEulerRad(Quaternion rotation)
{
	return Internal_ToEulerRad_Injected(rotation);
}

void Quaternion::Internal_ToAxisAngleRad(Quaternion q, Vector3& axis, float& angle)
{
	Internal_ToAxisAngleRad_Injected(q, axis, angle);
}

Vector3 Quaternion::NormalizeAngles(Vector3 angles)
{
	angles.x = NormalizeAngle(angles.x);
	angles.y = NormalizeAngle(angles.y);
	angles.z = NormalizeAngle(angles.z);
	return angles;
}

float Quaternion::NormalizeAngle(float angle)
{
	float modAngle = fmod(angle, 360.f);

	if (modAngle < 0.0f)
	{
		return modAngle + 360.0f;
	}

	return modAngle;
}