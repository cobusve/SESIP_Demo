/*
 * FreeRTOS OTA Update task.
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

#ifndef OTA_UPDATE_H
#define OTA_UPDATE_H

#include <stdint.h>
#include "FreeRTOS.h"

#include "core_mqtt.h"

#define OTA_UPDATE_ENABLED    ( 1 )

/**
 * @brief Function to start an OTA update task in the background.
 * Prerequisite: A valid MQTT connection should be established with AWS IoT core and the context
 * passed in as the parameter.
 *
 * @pram[in] pMQTTContext The context for MQTT connection with AWS IoT core.
 * @return pdTRUE if the OTA update task was successfully created.
 */

BaseType_t xStartOTAUpdateDemo( void );

BaseType_t xOTAProcessMQTTEvent( MQTTContext_t * pMQTTContext,
                                 struct MQTTPacketInfo * pPacketInfo,
                                 struct MQTTDeserializedInfo * pDeserializedInfo );

/**
 * @brief Validate the integrity of the new image to be activated.
 * @param[in] pCertificatePath The file path for the certificate, This can be certificate slot label name in PKCS11.
 * @param[in] pSignature  The signature for the image, received from server.
 * @param[in] signatureLength Length of the signature.
 */
BaseType_t xValidateImageSignature( uint8_t * pFilePath,
                                    char * pCertificatePath,
                                    uint8_t * pSignature,
                                    size_t signatureLength );


#endif /* ifndef OTA_UPDATE_H */
