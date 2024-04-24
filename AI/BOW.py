from sklearn.feature_extraction.text import CountVectorizer
# Sample documents
documents = [
    "The sky is blue.",
    "The sun is bright.",
    "The sun in the sky is bright.",
    "We can see the shining sun, the bright sun."
]
# Create the CountVectorizer object
vectorizer = CountVectorizer()

# Fit the vectorizer to the documents and transform the documents into BoW vectors
bow_matrix = vectorizer.fit_transform(documents)

# Get the vocabulary (unique words) learned by the vectorizer
vocabulary = vectorizer.get_feature_names_out()

# Print the BoW matrix and vocabulary
print("Bag of Words Matrix:")
print(bow_matrix.toarray())
print("\nVocabulary:")
print(vocabulary)
