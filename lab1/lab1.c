#ifndef ARTIFICIAL_INTELLIGANCE_OS_API_H
#define ARTIFICIAL_INTELLIGANCE_OS_API_H

#include <stdint.h>

// Типы данных
typedef uint8_t Byte;
typedef int32_t Status;
typedef int32_t UserID;
typedef int32_t VoiceID;

// Константы для статуса выполнения функций
#define SUCCESS 0
#define ERROR -1

// Подсистема биометрии. Тип биометрического данных
typedef enum {
    BIOMETRIC_FINGERPRINT,
    BIOMETRIC_FACE_IMAGE,
    BIOMETRIC_EYE_IMAGE,
    BIOMETRIC_VOICE,
    BIOMETRIC_GENETIC
} BiometricType;

// Подсистема биометрии. Результат идентификации пользователя
typedef struct {
    UserID user_id;
    Status status;
} BiometricResult;

// Функции для работы с биометрией
Status EnrollBiometricData(UserID user_id, BiometricType type, const Byte *data, size_t data_size);
BiometricResult IdentifyUserByBiometricData(BiometricType type, const Byte *data, size_t data_size);
Status DeleteBiometricData(UserID user_id, BiometricType type);

// Голосовая подсистема: функции распознавания и синтеза речи
Status RecognizeVoice(const Byte *audio_data, size_t data_size, VoiceID *recognized_id);
Status SynthesizeSpeech(const char *text, Byte *output_audio, size_t *output_size);

// Семантический анализ текста

typedef enum {
    CATEGORY_UNKNOWN = 0,      // Неизвестная категория
    CATEGORY_SPORTS,           // Спорт
    CATEGORY_MUSIC,            // Музыка
    CATEGORY_NEWS,             // Новости
    CATEGORY_ENTERTAINMENT,    // Развлечения
    CATEGORY_POLITICS,         // Политика
    CATEGORY_TECHNOLOGY,       // Технологии
    CATEGORY_SCIENCE,          // Наука
    CATEGORY_FINANCE,          // Финансы
    CATEGORY_HEALTH,           // Здоровье
    CATEGORY_TRAVEL,           // Путешествия
    CATEGORY_EDUCATION,        // Образование
    CATEGORY_FASHION,          // Мода
    CATEGORY_FOOD,             // Еда
    CATEGORY_LIFESTYLE,        // Образ жизни
    CATEGORY_HISTORY           // История
} TextCategory;

Status PerformTextSemanticAnalysis(const char *text, const char *local_sample_db_path, TextCategory *category, float *similarity_score);

// Подсистема распознавания текста
Status RecognizeTextFromImage(const Byte *image_data, size_t data_size, char *output_text, size_t *output_size);

// Подсистема распознавания эмоционального окраса
typedef enum {
    EMOTION_NEUTRAL,
    EMOTION_HAPPY,
    EMOTION_SAD,
    EMOTION_ANGRY,
    EMOTION_SURPRISED
} EmotionType;

Status DetectVoiceEmotion(const Byte *audio_data, size_t data_size, EmotionType *detected_emotion);
Status DetectTextEmotion(const char *text, EmotionType *detected_emotion);

#endif // ARTIFICIAL_INTELLIGANCE_OS_API_H
