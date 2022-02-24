export module box;

import <compare>;

export class Box
{
public:
	Box() = default;
	Box(const double l, const double w, const double h)
		: m_length{ l }, m_width{ w }, m_height{ h } {}

	double volume() const { return m_length * m_width * m_height; }

	double get_length() const { return m_length; }
	double get_width() const { return m_width; }
	double get_height() const { return m_height; }

	std::partial_ordering operator<=>(const Box& other_box) const
	{
		return volume() <=> other_box.volume();
	}

	std::partial_ordering operator<=>(const double other_volume) const
	{
		return volume() <=> other_volume;
	}

	bool operator==(const Box& other_box)
	{
		return m_length == other_box.m_length
			&& m_width  == other_box.m_width
			&& m_height == other_box.m_height;
	}

private:
	double m_length{ 1.0 };
	double m_width{ 1.0 };
	double m_height{ 1.0 };
};
