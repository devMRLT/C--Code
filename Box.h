class Box
{
	private:
		double height;
		double length;
		double width;
		
	public:
		Box(): height(0.0), length(0.0), width(0.0) { }
		Box(double newHeight, double newLength, double newWidth);
		
		double GetHeight() const;
		double GetLength() const;
		double GetWidth() const;
		
		void SetHeight(double newHeight);
		void SetLength(double newLength);
		void SetWidth(double newWidth);
		
		double FindVolume();
};

Box::Box(double newHeight, double newLength, double newWidth)
{
	SetHeight(newHeight);
	SetLength(newLength);
	SetWidth(newWidth);
}

double Box::GetHeight() const
{
	return height;
}

double Box::GetLength() const
{
	return length;
}

double Box::GetWidth() const
{
	return width;
}

void Box::SetHeight(double newHeight)
{
	height = newHeight;
}

void Box::SetLength(double newLength)
{
	length = newLength;
}

void Box::SetWidth(double newWidth)
{
	width = newWidth;
}

double Box::FindVolume()
{
	return GetHeight() * GetLength() * GetWidth();
}
