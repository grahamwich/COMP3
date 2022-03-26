//class Vector {
//public:
//	Vector();
//	Vector(const Vector &orgVector);
//	int getCapacity;
//	int getSize;
//	double* getData();
//	Vector& operator=(const Vector& rightOp);
//
//private:
//	double* data;
//	int capacity;
//	int size;
//
//};
//
//Vector& Vector::operator=(const Vector& rightOp) {
//	if (this == &rightOp) return *this;
//	this->capacity = rightOp.capacity;
//	this->size = rightOp.size;
//	for (int i = 0; i < capacity; i++) {
//		this->data[i] = rightOp.data[i];
//	}
//	return *this;
//	
//}